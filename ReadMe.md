`mesher`, a meshing command line for everyone and for no one.

Roberto Toro, May 2017

* Use `cgal_create_cmake_script` to generate a `CMakeList.txt` file
* Add `find_package(CGAL COMPONENTS ImageIO)` to the CMakeList.txt file, after `find_package(CGAL QUIET COMPONENTS Core )`
* Enter `cmake .` to generate the configuration file
* Finally, enter `make` to compile

