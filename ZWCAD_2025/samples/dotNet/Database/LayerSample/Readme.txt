Description: 
This application implements a command called "LayerSample" to demonstrate the operations of the layer.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use LayerSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the LayerSample.dll file in the output directory.
3. Execute the "LayerSample" command. If there is no layer named "Layer 1", the new layer will be created; otherwise, the layer name will be changed to "Layer 2".