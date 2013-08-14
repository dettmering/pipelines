CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'Unknown\'|variable_revision_number:11|show_window:False|notes:\x5B"Load the images by matching files in the folder against the unique text pattern for each stain\x3A \'Channel 1\' for protein, \'Channel 2\' for the nuclei image. The two images together comprise an image set."\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Default Input Folder\x7C.
    Check image sets for missing or duplicate files?:No
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:4
    Text that these images have in common (case-sensitive):_0001.tif
    Position of this image in each group:Channel 1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Load the input as images or objects?:Images
    Name this loaded image:OrigPhalloidin
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):_0002.tif
    Position of this image in each group:Channel 2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Load the input as images or objects?:Images
    Name this loaded image:OrigRef
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):_0003.tif
    Position of this image in each group:3
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:OrigDNA
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):_0000.tif
    Position of this image in each group:4
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:OrigPOI
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

IdentifyPrimaryObjects:[module_num:2|svn_version:\'Unknown\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:OrigDNA
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):18,40
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0,1.0
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:20
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

Smooth:[module_num:3|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:OrigPhalloidin
    Name the output image:SmoothPhalloidin
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:20.0
    Edge intensity difference:0.1

IdentifySecondaryObjects:[module_num:4|svn_version:\'Unknown\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells
    Select the method to identify the secondary objects:Propagation
    Select the input image:SmoothPhalloidin
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:10
    Regularization factor:0.05
    Name the outline image:SecondaryOutlines
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified secondary objects?:No
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Discard secondary objects that touch the edge of the image?:No
    Discard the associated primary objects?:No
    Name the new primary objects:FilteredNuclei
    Retain outlines of the new primary objects?:No
    Name the new primary object outlines:FilteredNucleiOutlines
    Select the measurement to threshold with:None
    Fill holes in identified objects?:Yes

IdentifyTertiaryObjects:[module_num:5|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the larger identified objects:Cells
    Select the smaller identified objects:Nuclei
    Name the tertiary objects to be identified:Cytoplasm
    Name the outline image:CytoplasmOutlines
    Retain outlines of the tertiary objects?:No

MeasureObjectIntensity:[module_num:6|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:3
    Select an image to measure:OrigPOI
    Select an image to measure:OrigPhalloidin
    Select an image to measure:OrigRef
    Select objects to measure:Cells
    Select objects to measure:Cytoplasm
    Select objects to measure:Nuclei

ExportToSpreadsheet:[module_num:7|svn_version:\'Unknown\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
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
