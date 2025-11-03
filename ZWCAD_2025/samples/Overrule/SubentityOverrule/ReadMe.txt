Description: 
This application demonstrates the use of the AcDbSubentityOverrule class, which can overrule the subentity related operations that implemented in AcDbEntity.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use SubentityOverrule.zrx:
1. Start ZWCAD and open a new drawing and draw a polyline with multi nodes.
2. Run APPLOAD command and load the SubentityOverrule.zrx file in the output directory.
3. Execute the "HighlihtSubEdge" command and select a sub-edge of the polyline, and you can see the sub-edge is highlighted and a red sub-egde is created.
4. Execute the "AddSubentityOverrule" command to add the SubentityOverrule(Execute the "RemoveSubentityOverrule" to remove). Then repeat the step 3. You can find that there is not a red sub-egde to be created because the subentPtr interface of the polyline returns NULL after adding the overrule.