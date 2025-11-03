Description: 
This application demonstrates how to receive notification of the DBObject events. 

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use ObjectReactor.dll:
1. Start ZWCAD and open a new drawing, and draw a circle.
2. Run NETLOAD command and load the ObjectReactor.dll file in the output directory.
3. Execute the "AddObjReactor" command to add the ObjectReactor for the circle(Execute the "DelObjReactor" to remove). The reactor will be triggered during modifying, copying and deleting this circle. For the detailed scenarios that will trigger the reactor, see the description of the events in the development document.