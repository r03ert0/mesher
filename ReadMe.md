`mesher`, a meshing command line for everyone and for no one.

Roberto Toro, April 2019

## Installation of CGAL and compilation

* Download CGAL, for example https://codeload.github.com/CGAL/cgal/zip/releases/CGAL-4.13.1
* Compile and install using `cd $LOCATION/CGAL-4.13.1; cmake .; make install`. The `make install` bit
  is the only way I have figured thus far to make my code find `ImageIO`.
* The `CmakeList.txt` file was created using the script `cgal_create_CMakeLists -c ImageIO` (found at `CGAL-4.13.1/Scripts`).
* Compile using `cmake .; make`.

## Mesh a binary mask

First, you need to convert the binary mask into a grey scale image. You can use `volume`for this (https://github.com/r03ert0/volume)

`./volume mask.nii.gz -threshold 1,1 -mult 10000 -boxFilter 1 2 -o greylevel.inr`

Next, use mesher like this:

`./mesh_a_3d_gray_image greylevel.inr mesh.off`

Finally, you can convert the `.off` mesh file into `.ply` for example by using `meshgeometry`:

`./meshgeometry_mac -i mesh.off -o mesh.ply`
