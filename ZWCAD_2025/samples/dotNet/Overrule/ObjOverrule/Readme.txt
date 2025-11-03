Description: 
This application demonstrates the use of the ObjectOverrule class, which can overrule the operations that DBObject class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use ObjOverrule.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the ObjOverrule.dll file in the output directory.
3. Execute the "AddObjectOverruleCanCopy" or "AddObjectOverruleCanNotCopy" command to add the ObjectOverrule(Execute the "RemoveObjectOverrule" to remove). Draw a polyline and copy it to paste. You can find that the color of the copied polyline turns red after the "AddObjectOverruleCanCopy" command and the polyline will forbid to be copied after the "AddObjectOverruleCanNotCopy" command.