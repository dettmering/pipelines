CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Regular expressions
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Default Input Folder\x7CNone
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):0000.tif
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:DIC
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

MeasureImageQuality:[module_num:2|svn_version:\'11705\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Calculate metrics for which images?:All loaded images
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:
    Include the image rescaling value?:Yes
    Calculate blur metrics?:Yes
    Spatial scale for blur measurements:20
    Calculate saturation metrics?:No
    Calculate intensity metrics?:No
    Calculate thresholds?:No
    Use all thresholding methods?:No
    Select a thresholding method:Otsu Global
    Typical fraction of the image covered by objects:0.1
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground

ImageMath:[module_num:3|svn_version:\'10718\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Invert
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:DICInverted
    Image or measurement?:Image
    Select the first image:DIC
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

ApplyThreshold:[module_num:4|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:DICInverted
    Name the output image:DICThresholded
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Otsu Global
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

MeasureImageAreaOccupied:[module_num:5|svn_version:\'10563\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Measure the area occupied in a binary image, or in objects?:Binary Image
    Select objects to measure:None
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:DICThresholded

SaveImages:[module_num:6|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:DICThresholded
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DIC
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_binarized
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7Cimages
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:7|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:No
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:No
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder\x7CNone
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:Yes
    Press button to select measurements to export:
    Data to export:Do not use
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
