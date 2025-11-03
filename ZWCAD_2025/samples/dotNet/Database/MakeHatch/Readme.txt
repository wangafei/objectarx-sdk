Description: 
This application implements a command to demonstrate the creation of the hatch

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use MakeHatch.dll:
1. Start ZWCAD and open a new drawing.
2. Draw several concentric circles or concentric closed polylines and the boundaries cannot intersect each other.
3. Run NETLOAD command and load the MakeHatch.dll file in the output directory.
4. Execute the "TestCreateHatch" command. Firstly, select the entity(s) drawn in the second step, which is the boundary of the hatch to be created. Then specify the style of ths hatch. 