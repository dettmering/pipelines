CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B"Load the images by matching files in the folder against the unique text pattern for each stain\x3A \'Channel 1\' for protein, \'Channel 2\' for the nuclei image. The two images together comprise an image set."\x5D]
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
    Image count:2
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
    Name this loaded image:OrigProtein
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):_0003.tif
    Position of this image in each group:Channel 2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Load the input as images or objects?:Images
    Name this loaded image:OrigDNA
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes

IdentifyPrimaryObjects:[module_num:2|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\'Identify the nuclei from the nuclear stain image. \'\x5D]
    Select the input image:OrigDNA
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):5,50
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.01,1.0
    Approximate fraction of image covered by objects?:0.1
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:17
    Suppress local maxima that are closer than this minimum allowed distance:5
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:NucOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:MoG Adaptive
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

IdentifySecondaryObjects:[module_num:3|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\'Identify the cells by using the nuclei as a "seed" region, then growing outwards until stopped by the image threshold or by a neighbor. The Distance-B method is used to delineate the boundary between neighboring cells.\'\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells
    Select the method to identify the secondary objects:Distance - B
    Select the input image:OrigProtein
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0,1
    Approximate fraction of image covered by objects?:10%
    Number of pixels by which to expand the primary objects:6
    Regularization factor:0.05
    Name the outline image:CellOutlines
    Manual threshold:0
    Select binary image:Do not use
    Retain outlines of the identified secondary objects?:Yes
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Discard secondary objects that touch the edge of the image?:No
    Discard the associated primary objects?:No
    Name the new primary objects:FilteredNuclei
    Retain outlines of the new primary objects?:No
    Name the new primary object outlines:FilteredNucleiOutlines
    Select the measurement to threshold with:None
    Fill holes in identified objects?:No

IdentifyTertiaryObjects:[module_num:4|svn_version:\'10300\'|variable_revision_number:1|show_window:False|notes:\x5B\'Identify the cytoplasm by "subtracting" the nuclei objects from the cell objects.\'\x5D]
    Select the larger identified objects:Cells
    Select the smaller identified objects:Nuclei
    Name the tertiary objects to be identified:Cytoplasm
    Name the outline image:Do not use
    Retain outlines of the tertiary objects?:No

MeasureObjectIntensity:[module_num:5|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\'Measure intensity features from nuclei, cell and cytoplasm objects against the corrected images.\'\x5D]
    Hidden:1
    Select an image to measure:OrigProtein
    Select objects to measure:Nuclei
    Select objects to measure:Cells
    Select objects to measure:Cytoplasm

CalculateMath:[module_num:6|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\'Calculate the nuclei-to-cell ratio of the mean protein intensity.\'\x5D]
    Name the output measurement:Ratio1
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Nuclei
    Select the numerator measurement:Intensity_MeanIntensity_OrigProtein
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cells
    Select the denominator measurement:Intensity_MeanIntensity_OrigProtein
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:7|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\'Calculate the cytoplasm-to-cell ratio of the mean protein intensity.\'\x5D]
    Name the output measurement:Ratio2
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Cytoplasm
    Select the numerator measurement:Intensity_MeanIntensity_OrigProtein
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cells
    Select the denominator measurement:Intensity_MeanIntensity_OrigProtein
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:8|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\'Calculate the cytoplasm-to-nucleus ratio of the mean protein intensity.\'\x5D]
    Name the output measurement:Ratio3
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Nuclei
    Select the numerator measurement:Intensity_MeanIntensity_OrigProtein
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cytoplasm
    Select the denominator measurement:Intensity_MeanIntensity_OrigProtein
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

OverlayOutlines:[module_num:9|svn_version:\'10672\'|variable_revision_number:2|show_window:False|notes:\x5B\'Overlay the nucleus and cell outlines on the protein image.\'\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:OrigProtein
    Name the output image:Outlined
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:NucOutlines
    Select outline color:Blue
    Select outlines to display:CellOutlines
    Select outline color:Green

SaveImages:[module_num:10|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B"Save the nuclei overlay image as an 8-bit TIF, appending the text \'_Outlined\' to the original filename of the protein image."\x5D]
    Select the type of image to save:Image
    Select the image to save:Outlined
    Select the objects to save:None
    Select the module display window to save:OutlinedNuc
    Select method for constructing file names:From image filename
    Select image name for file prefix:OrigProtein
    Enter single file name:OrigProtein
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_Outlined
    Select file format to use:jpg
    Output file location:Default Output Folder\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:11|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B"Export any measurements to a comma-delimited file (.csv). The measurements made for the nuclei, cell and cytoplasm objects will be saved to separate .csv files, in addition to the per-image .csv\'s."\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:No
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:No
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder\x7C.
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
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
