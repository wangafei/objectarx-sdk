Description: 
This application implements three commands to demonstrate the use of the acedDragGen method, which prompts the user to modify a selection set by graphically dragging its entities(move, rotate and scale). 

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use DragEntities.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the DragEntities.zrx file in the output directory.
3. Execute the "DragMoveEntitys" command, which moves entity(s) in the selection set to the target position by specifying the base point and target point.
4. Execute the "DragRotateEntitys" command, which rotates entity(s) in the selection set by the angle between the reference line(the origin point to the moving point) and x-axis.
5. Execute the "DragScaleEntitys" command, which scales entity(s) in the selection set at the scaling factor which is determined by the proportion of the lengths of the line formed by the moving point and the origin point and the line formed by the base point and the origin point.