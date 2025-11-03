Description: 
This application demonstrates the use of the TransformOverrule class, which can overrule the transform related operations that the Entity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use TransformOverruleSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the TransformOverruleSample.dll file in the output directory.
3. Execute the "AddTransformOverrule" command to add the TransformOverrule(Execute the "RemoveTransformOverrule" to remove). Draw a polyline and explode it by "EXPLODE" command. You can find that the polyline is exploded to a cylinder.