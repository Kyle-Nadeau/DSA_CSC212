The following file will demonstrate how to compile the cpp and python files in order to run our code.
You can refer to the Report for further instructions or clarifying explanations.

If you are using CLION:
  For main.cpp, add to cmakelists in your current working directory, and run the code.
  There are no needed CLA's, the only input will be within the terminal by the user of the program,
  the output will consist of a file within the users working directory named "file," This contains the 
  instructions the python program will use to map / plot the functions.
  
  For the plotter.py file, we will create a new run configuration, with the working directory set to the file path, 
  for example mine is C:\Users\kylen\CLionProjects\DSA\ for the working directory and C:\Users\kylen\CLionProjects\DSA\plotter.py
  as the script path. Next, specify the file paths as arguments for your input and output file, as well as a degree at which the algorithm will 
  plot at. It will consist of the input file, the output png image and degrees as seen below. 
  
    C:\Users\kylen\CLionProjects\DSA\cmake-build-debug\file C:\Users\kylen\CLionProjects\DSA\cmake-build-debug\image.png 90
  
  After this, run the program and view the png output.



If you are using G++:
  For the main.cpp, simply open your g++ compiler and use:  
  
    g++ main.cpp -o main && ./main 
    
 This will result in an output file named "file" within the same directory as the main.cpp file.
 
 For the python file use: 
 
     g++ python3 plotter.py file.txt image.png <degree for turns>
  
   

If you are using GCC:
  For the main.cpp, simply open your gcc compiler and use:
  
    gcc main.cpp -o main
  
This will result in an output file named "file" within the same directory as the main.cpp file.
  
  
For the python file, it will not function using gcc, however you can use the terminal to enter:
  
  
    python plotter.py file.txt image.png <degrees>
