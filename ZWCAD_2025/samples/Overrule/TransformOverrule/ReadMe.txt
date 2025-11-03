Description: 
This application demonstrates the use of the AcDbTransformOverrule class, which can overrule the transform related operations that the AcDbEntity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use TransformOverrule.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the TransformOverrule.zrx file in the output directory.
3. Execute the "AddTransformOverrule" command to add the TransformOverrule(Execute the "RemoveTransformOverrule" to remove). Draw a polyline and explode it by "EXPLODE" command. You can find that the polyline is exploded to a cylinder.