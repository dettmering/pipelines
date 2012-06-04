CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:10415

LoadImages:[module_num:1|svn_version:\'10372\'|variable_revision_number:7|show_window:True|notes:\x5B"Load the images by matching files in the folder against the unique text pattern \'.tif\'"\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:No
    Input image file location:Default Input Folder\x7C.
    Check image sets for missing or duplicate files?:No
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Image count:1
    Text that these images have in common (case-sensitive):.tif
    Position of this image in each group:.tif
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Name this loaded image:RGB
    Channel number:1

ColorToGray:[module_num:2|svn_version:\'10318\'|variable_revision_number:2|show_window:True|notes:\x5B\'Split the color image into the individual RGB channels, giving each a unique name.\'\x5D]
    Select the input image:RGB
    Conversion method:Split
    Image type\x3A:RGB
    Name the output image:OrigGray
    Relative weight of the red channel:1
    Relative weight of the green channel:1
    Relative weight of the blue channel:1
    Convert red to gray?:Yes
    Name the output image:OrigRed
    Convert green to gray?:Yes
    Name the output image:OrigGreen
    Convert blue to gray?:Yes
    Name the output image:OrigBlue
    Channel count:1
    Channel number\x3A:Red\x3A 1
    Relative weight of the channel:1
    Image name\x3A:Channel1

InvertForPrinting:[module_num:3|svn_version:\'10300\'|variable_revision_number:1|show_window:True|notes:\x5B\'Invert the color of each channel image for better display.\'\x5D]
    Input image type:Grayscale
    Use a red image?:Yes
    Select the red image:OrigRed
    Use a green image?:Yes
    Select the green image:OrigGreen
    Use a blue image?:Yes
    Select the blue image:OrigBlue
    Select the color image:None
    Output image type:Grayscale
    Produce a red image?:Yes
    Name the red image:InvertedDisplayRed
    Produce a green image?:Yes
    Name the green image:InvertedDisplayGreen
    Produce a blue image?:Yes
    Name the blue image:InvertedDisplayBlue
    Name the inverted color image:InvertedColor

GrayToColor:[module_num:4|svn_version:\'10341\'|variable_revision_number:2|show_window:True|notes:\x5B\'Combine the individual inverted channels into a color RGB image.\'\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:InvertedDisplayRed
    Select the input image to be colored green:InvertedDisplayGreen
    Select the input image to be colored blue:InvertedDisplayBlue
    Name the output image:ColorImage
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:None
    Select the input image to be colored magenta:None
    Select the input image to be colored yellow:None
    Select the input image that determines brightness:None
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

SaveImages:[module_num:5|svn_version:\'10411\'|variable_revision_number:6|show_window:True|notes:\x5B"Save the color image as a BMP file, appending the text \'Inverted\' to the original filename of the color image."\x5D]
    Select the type of image to save:Image
    Select the image to save:ColorImage
    Select the module display window to save:ColorImage
    Select method for constructing file names:From image filename
    Select image name for file prefix:RGB
    Enter single file name:RGB
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:Inverted
    Select file format to use:bmp
    Output file location:Default Output Folder\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Select colormap:gray
    Update file names within CellProfiler?:No
    Create subfolders in the output folder?:No
