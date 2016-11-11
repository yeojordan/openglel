
######Semester 2, 2016

## openglel

### Repository Structure
- *docs* - Assignment specification and other assignment relevant documents
- *report* - Files needed to build the report, written in LaTeX, also contains the current pdf of the report
- *src* - Source code required for particular tasks of the assignment. 


### Running the Program
While inside the *src* directory.

- Running the program 
	- ``make``

- Removing executables and object files
	- ``make clean``

### Screenshots
![](https://puu.sh/seGfz/bf4c856ec7.png)
![](https://puu.sh/seGfd/5ce4e1f9d3.png)
![](https://puu.sh/seGpp/a6f05a266b.png)

### Sources Files
Each cpp file has a corresponding header file to allow for easier organisation of source code. 


anchor.cpp & anchor.h

-  Contains the source code and appropriate foward declaration to create the anchor


axis.cpp & axis.h

-  Contains the source code and appropriate forward declaration to draw an x,y,z axis

bubbles.cpp & bubble.h

-  Contains the source code and appropriate foward declaration to creates bubbles

cage.cpp & cage.h

-  Contains the source code and appropriate foward declaration to create a cage


chain.cpp & chain.h

-  Contains the source code and appropriate foward declaration to create a chain

gl.h

-  Contains the appropriate foward declarations for necessary packages

imageloader.cpp & imageloader.h

-  Contains the source code and appropriate foward declaration to load textures

main.cpp & main.h

-  Contains the source code and appropriate foward declaration for the main

mast.cpp & mast.h

-  Contains the source code and appropriate foward declaration to draw a mast


rock.cpp & rock.h

-  Contains the source code and appropriate foward declaration to create a rock

solidCylinder.cpp & solidCylinder.h

-  Contains the source code and appropriate foward declaration to create a solid cylinder

wheel.cpp & wheel.h

-  Contains the source code and appropriate foward declaration to create a wheel

