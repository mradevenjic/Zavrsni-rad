# Zavrsni-rad

Sve potrebne biblioteke se nalaze unutar "Middleware" foldera.


Visual Studio 

Project > Properties > C/C++ > General > Additional Include Directories: 
$(ProjectDir);$(ProjectDir)..\Middleware\Qt\include;$(ProjectDir)..\Middleware\glew\include;$(ProjectDir)..\Middleware\glm

Project > Properties > Linker > General > Additional Library Directories:
$(ProjectDir)..\Middleware\Qt\lib;$(ProjectDir)..\Middleware\glew\lib

Project > Properties > Linker > Input > Additional Dependencies:
opengl32.lib;glew32d.lib;QtCored4.lib;QtGuid4.lib;QtOpenGld4.lib;
