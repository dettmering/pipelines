CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:10415

LoadImages:[module_num:1|svn_version:\'10372\'|variable_revision_number:7|show_window:True|notes:\x5B\'Load the images by matching files in the folder against the unique text pattern for each stain\x3A d0.tif for nuclei, d1.tif for the PH3 image, d2.tif for the cell stain image. The three images together comprise an image set.\'\x5D]
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
    Image count:3
    Text that these images have in common (case-sensitive):d0.tif
    Position of this image in each group:d0.tif
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Name this loaded image:OrigBlue
    Channel number:1
    Text that these images have in common (case-sensitive):d1.tif
    Position of this image in each group:d1.tif
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Name this loaded image:OrigGreen
    Channel number:1
    Text that these images have in common (case-sensitive):d2.tif
    Position of this image in each group:d2.tif
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Name this loaded image:OrigRed
    Channel number:1

Crop:[module_num:2|svn_version:\'10300\'|variable_revision_number:2|show_window:True|notes:\x5B\'Crop the nuclei image down to a 200 x 200 rectangle by entering specific coordinates.\'\x5D]
    Select the input image:OrigBlue
    Name the output image:CropBlue
    Select the cropping shape:Rectangle
    Select the cropping method:Coordinates
    Apply which cycle\'s cropping pattern?:First
    Left and right rectangle positions:1,200
    Top and bottom rectangle positions:1,200
    Coordinates of ellipse center:500,500
    Ellipse radius, X direction:400
    Ellipse radius, Y direction:200
    Use Plate Fix?:No
    Remove empty rows and columns?:Edges
    Select the masking image:None
    Select the image with a cropping mask:None
    Select the objects:None

Crop:[module_num:3|svn_version:\'10300\'|variable_revision_number:2|show_window:True|notes:\x5B\'Use the same cropping from the nuclei image for the PH3 image.\'\x5D]
    Select the input image:OrigGreen
    Name the output image:CropGreen
    Select the cropping shape:Rectangle
    Select the cropping method:Coordinates
    Apply which cycle\'s cropping pattern?:First
    Left and right rectangle positions:1,200
    Top and bottom rectangle positions:1,200
    Coordinates of ellipse center:500,500
    Ellipse radius, X direction:400
    Ellipse radius, Y direction:200
    Use Plate Fix?:No
    Remove empty rows and columns?:Edges
    Select the masking image:None
    Select the image with a cropping mask:None
    Select the objects:None

Crop:[module_num:4|svn_version:\'10300\'|variable_revision_number:2|show_window:True|notes:\x5B\'Use the same cropping from the nuclei image for the cell stain image.\'\x5D]
    Select the input image:OrigRed
    Name the output image:CropRed
    Select the cropping shape:Rectangle
    Select the cropping method:Coordinates
    Apply which cycle\'s cropping pattern?:First
    Left and right rectangle positions:1,200
    Top and bottom rectangle positions:1,200
    Coordinates of ellipse center:500,500
    Ellipse radius, X direction:400
    Ellipse radius, Y direction:200
    Use Plate Fix?:No
    Remove empty rows and columns?:Edges
    Select the masking image:None
    Select the image with a cropping mask:None
    Select the objects:None

IdentifyPrimaryObjects:[module_num:5|svn_version:\'10372\'|variable_revision_number:7|show_window:True|notes:\x5B\'Identify the nuclei from the nuclear stain image. Some manual adjustment of the smoothing filter size and maxima supression distance is required to optimize segmentation.\'\x5D]
    Select the input image:CropBlue
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):8,80
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0,1
    Approximate fraction of image covered by objects?:0.1
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:5
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:NucOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:MoG Global
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifySecondaryObjects:[module_num:6|svn_version:\'10300\'|variable_revision_number:7|show_window:True|notes:\x5B\'Identify the cells by using the nuclei as a "seed" region, then growing outwards until stopped by the image threshold or by a neighbor. The Propagation method is used to delineate the boundary between neighboring cells.\'\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells
    Select the method to identify the secondary objects:Propagation
    Select the input image:CropRed
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0,1
    Approximate fraction of image covered by objects?:10%
    Number of pixels by which to expand the primary objects:10
    Regularization factor:0.05
    Name the outline image:Do not use
    Manual threshold:0
    Select binary image:Do not use
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

IdentifyTertiaryObjects:[module_num:7|svn_version:\'10300\'|variable_revision_number:1|show_window:True|notes:\x5B\'Identify the cytoplasm by "subtracting" the nuclei objects from the cell objects.\'\x5D]
    Select the larger identified objects:Cells
    Select the smaller identified objects:Nuclei
    Name the tertiary objects to be identified:Cytoplasm
    Name the outline image:Do not use
    Retain outlines of the tertiary objects?:No

MeasureObjectIntensity:[module_num:8|svn_version:\'10300\'|variable_revision_number:3|show_window:True|notes:\x5B\'Measure intensity features from nuclei, cell and cytoplasm objects against the cropped images.\'\x5D]
    Hidden:2
    Select an image to measure:CropBlue
    Select an image to measure:CropGreen
    Select objects to measure:Nuclei
    Select objects to measure:Cells
    Select objects to measure:Cytoplasm

MeasureObjectSizeShape:[module_num:9|svn_version:\'1\'|variable_revision_number:1|show_window:True|notes:\x5B\'Measure morphological features from the cell, nuclei and cytoplasm objects.\'\x5D]
    Select objects to measure:Nuclei
    Select objects to measure:Cells
    Select objects to measure:Cytoplasm
    Calculate the Zernike features?:No

OverlayOutlines:[module_num:10|svn_version:\'10300\'|variable_revision_number:2|show_window:True|notes:\x5B\'Overlay the nucleus outlines on the cropped nuclear image.\'\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:CropBlue
    Name the output image:OutlinedNuc
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:NucOutlines
    Select outline color:White

SaveImages:[module_num:11|svn_version:\'10411\'|variable_revision_number:6|show_window:True|notes:\x5B"Save the overlay image as an 8-bit TIF, appending the text \'outline\' to the original filename of the nuclei image."\x5D]
    Select the type of image to save:Image
    Select the image to save:OutlinedNuc
    Select the module display window to save:OutlinedNuc
    Select method for constructing file names:From image filename
    Select image name for file prefix:OrigBlue
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:outline
    Select file format to use:tif
    Output file location:Default Output Folder\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Select colormap:gray
    Update file names within CellProfiler?:No
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:12|svn_version:\'10251\'|variable_revision_number:7|show_window:True|notes:\x5B"Export any measurements to a comma-delimited file (.csv). The measurements made for the nuclei, cell and cytoplasm objects will be saved to separate .csv files, in addition to the per-image .csv\'s."\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:No
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:No
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder\x7C.
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements?:No
    Press button to select measurements to export:None\x7CNone
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:Image.csv
    Use the object name for the file name?:No
    Data to export:Nuclei
    Combine these object measurements with those of the previous object?:No
    File name:Nuclei.csv
    Use the object name for the file name?:No
    Data to export:Cells
    Combine these object measurements with those of the previous object?:No
    File name:Cells.csv
    Use the object name for the file name?:No
    Data to export:Cytoplasm
    Combine these object measurements with those of the previous object?:No
    File name:Cytoplasm.csv
    Use the object name for the file name?:No
