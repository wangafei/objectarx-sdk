Description: 
This application demonstrates the use of the AcDbGeometryOverrule class, which can overrule the geometry related operations implemented in the AcDbEntity class.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use GeometryOverrule.zrx:
1. Start ZWCAD and open a new drawing. Then draw a line, a polyline, and a circle, and they intersect each other.
2. Run APPLOAD command and load the GeometryOverrule.zrx file in the output directory.
3. Execute the "getGeoExtentsOfThisEntity" and "getIntersectionOfTwoEntities" commands. They can calculate the bounding box of the selected entities or the intersection(s) between the selected entities.
4. Execute the "addGeometryOverrule" command to add the GeometryOverrule(Execute the "removeGeometryOverrule" to remove). Then execute the "getGeoExtentsOfThisEntity" and "getIntersectionOfTwoEntities" commands again. Comparing with the results in step 3, you can find that the data has become what is customized by the program.
