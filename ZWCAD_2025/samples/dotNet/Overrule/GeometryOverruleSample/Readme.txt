Description: 
This application demonstrates the use of the GeometryOverrule class, which can overrule the geometry related operations implemented in the Entity class.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use GeometryOverruleSample.dll:
1. Start ZWCAD and open a new drawing. Then draw a line, a polyline, and a circle, and they intersect each other.
2. Run NETLOAD command and load the GeometryOverruleSample.dll file in the output directory.
3. Execute the "GetGeoExtentsOfThisEntity" and "GetIntersectionOfTwoEntities" commands. They can calculate the bounding box of the selected entities or the intersection(s) between the selected entities.
4. Execute the "GeometryOverruleOnOff" command to add the GeometryOverrule(Execute the "GeometryOverruleOnOff" again to remove). Then execute the "GetGeoExtentsOfThisEntity" and "GetIntersectionOfTwoEntities" commands again. Comparing with the results in step 3, you can find that the data has become what is customized by the program.