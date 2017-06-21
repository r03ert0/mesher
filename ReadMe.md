`mesher`, a meshing command line for everyone and for no one.

Roberto Toro, May 2017

* Install cgal using `brew install --with-imaging cgal` 

* Use `cgal_create_cmake_script` to generate a `CMakeList.txt` file
* Add `find_package(CGAL COMPONENTS ImageIO)` to the CMakeList.txt file, after `find_package(CGAL QUIET COMPONENTS Core )`
* Enter `cmake .` to generate the configuration file
    ( if you do not have cmake: `brew install cmake` )
* `brew install gmp`
    ( if gmp is already installed but needs to be relinked: `brew unlink gmp && brew link gmp` )
    
* Finally, enter `make` to compile

## Mesh a binary mask

First, you need to convert the binary mask into a grey scale image. You can use `volume`for this (https://github.com/r03ert0/volume)

./volume mask.nii.gz -threshold 1,1 -mult 10000 -boxFilter 1 2 -o greylevel.inr

Next, use mesher like this:

./mesh_a_3d_gray_image greylevel.inr mesh.off

Finally, you can convert the `.off` mesh file into `.ply` for example by using `meshgeometry`:

./meshgeometry_mac -i mesh.off -o mesh.ply
