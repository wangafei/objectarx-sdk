Description: 
This application demonstrates the use of the GripOverrule class, which can overrule the grip related operations that Entity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use GripOverruleSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the GripOverruleSample.dll file in the output directory.
3. Execute the "AddGripOverrule" command to add the GripOverrule(Execute the "RemoveGripOverrule" to remove). Then draw a line and select it. If the length of the line is less than 1000, the grip will not be displayed.