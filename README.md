# MaterialInstanceCreator
This project/plugin can be used to create a lot of material instance easily but with the help of editor utility window.(Not Runtime)

you can use this plugin to create, modify and save material instances in the editor.
But you need some knowledge of coding and editor utility services.
There are only two nodes in this plugin "Mark Package to save", "Create Material Instances".
You can do changes in constant materials by using "Material Editing section". Like "Set Instance Parent","Set Scalar, vector, Texture parameters".
But you cannot save that using editor services everytime you restart or reopen your editor it will gone. So this plugn gives you the facility to save it permanently and create so many instances at once by code and save them.
Just do the modification and then call the "Mark Package to save" function on that.
You can create instances by calling "Create Material Instances", you need to pass path,name,parent of newly creating instance.
Enjoy!.
