#include <CGAL/Surface_mesh_default_triangulation_3.h>
#include <CGAL/Surface_mesh_default_criteria_3.h>
#include <CGAL/Complex_2_in_triangulation_3.h>
#include <CGAL/IO/Complex_2_in_triangulation_3_file_writer.h>
#include <fstream>
#include <CGAL/make_surface_mesh.h>
#include <CGAL/Gray_level_image_3.h>
#include <CGAL/Implicit_surface_3.h>

// default triangulation for Surface_mesher
typedef CGAL::Surface_mesh_default_triangulation_3 Tr;

// c2t3
typedef CGAL::Complex_2_in_triangulation_3<Tr> C2t3;
typedef Tr::Geom_traits GT;
typedef CGAL::Gray_level_image_3<GT::FT, GT::Point_3> Gray_level_image;
typedef CGAL::Implicit_surface_3<GT, Gray_level_image> Surface_3;

int main(int argc, char *argv[])
{
    /*
        argv[1]: path to input .inr greyscale volume. The mesh constructed at level 5000
        argv[2]: path to output .off mesh
    */
    
    Tr tr;            // 3D-Delaunay triangulation
    C2t3 c2t3 (tr);   // 2D-complex in 3D-Delaunay triangulation

    char *path;
    float xdim,ydim,zdim;
    float vx,vy,vz;
    float max,pixdim;
    
    path=argv[1];

    Gray_level_image image(path, 5000.0f);

    xdim=(float)image.xdim();
    ydim=(float)image.ydim();
    zdim=(float)image.zdim();
    vx=(float)image.vx();
    vy=(float)image.vy();
    vz=(float)image.vz();
    max=xdim;
    if(max<ydim)
        max=ydim;
    if(max<zdim)
        max=zdim;
    pixdim=vx;
    if(pixdim>vy)
        pixdim=vy;
    if(pixdim>vz)
        pixdim=vz;

    std::cout << "xdim: " << xdim << "\n";
    std::cout << "ydim: " << ydim << "\n";
    std::cout << "zdim: " << zdim << "\n";
    std::cout << "max:  " <<  max << "\n";
    std::cout << "vx: " << vx << "\n";
    std::cout << "vy: " << vy << "\n";
    std::cout << "vz: " << vz << "\n";
    std::cout << "pixdim: " << pixdim << "\n";

    GT::Point_3 bounding_sphere_center(xdim/2.0,ydim/2.0, zdim/2.0);
    GT::FT bounding_sphere_squared_radius = (max/2.0)*(max/2.0)*2.;
    GT::Sphere_3 bounding_sphere(bounding_sphere_center, bounding_sphere_squared_radius);
    Surface_3 surface(image, bounding_sphere, 1e-5);

    CGAL::Surface_mesh_default_criteria_3<Tr> criteria(30.0, pixdim*2.5, pixdim*2.5);

    CGAL::make_surface_mesh(c2t3, surface, criteria, CGAL::Manifold_tag());

    std::ofstream out(argv[2]);
    CGAL::output_surface_facets_to_off (out, c2t3);
    std::cout << "Final number of points: " << tr.number_of_vertices() << "\n";
}