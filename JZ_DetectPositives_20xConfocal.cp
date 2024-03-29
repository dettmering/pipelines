CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\'This pipeline is optimized for\x3A Lung cryosections, 10 um thickness, confocal, 20x objective, DAPI + 2 ch\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Regular expressions
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Default Input Folder\x7C.
    Check image sets for missing or duplicate files?:No
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:3
    Text that these images have in common (case-sensitive):1.tif
    Position of this image in each group:d0.tif
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Load the input as images or objects?:Images
    Name this loaded image:DAPI
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):2.tif
    Position of this image in each group:2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:FITC
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):3.tif
    Position of this image in each group:3
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:PI
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

MeasureImageQuality:[module_num:2|svn_version:\'11705\'|variable_revision_number:4|show_window:False|notes:\x5B\'Measures Focus Score\'\x5D]
    Calculate metrics for which images?:Select...
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:DAPI
    Include the image rescaling value?:No
    Calculate blur metrics?:Yes
    Spatial scale for blur measurements:60
    Calculate saturation metrics?:No
    Calculate intensity metrics?:No
    Calculate thresholds?:No
    Use all thresholding methods?:No
    Select a thresholding method:Otsu Global
    Typical fraction of the image covered by objects:0.1
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground

FlagImage:[module_num:3|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\'Skips images with a too low focus score. When recording confocal tile scans, this is used to exclude out-of-focus images.\'\x5D]
    Hidden:1
    Hidden:1
    Name the flag\'s category:ScoreTooLow
    Name the flag:ScoreTooLow
    Flag if any, or all, measurement(s) fails to meet the criteria?:Flag if any fail
    Skip image set if flagged?:Yes
    Flag is based on:Whole-image measurement
    Select the object whose measurements will be used to flag:None
    Which measurement?:ImageQuality_FocusScore_DAPI
    Flag images based on low values?:Yes
    Minimum value:0.2
    Flag images based on high values?:No
    Maximum value:1

IdentifyPrimaryObjects:[module_num:4|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\'Identify the nuclei from the nuclear stain image. Some manual adjustment of the smoothing filter size and maxima supression distance is required to optimize segmentation.\'\x5D]
    Select the input image:DAPI
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1.5
    Lower and upper bounds on threshold:0,1.0
    Approximate fraction of image covered by objects?:0.1
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:14
    Suppress local maxima that are closer than this minimum allowed distance:5
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:NucOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
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

IdentifySecondaryObjects:[module_num:5|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Green
    Select the method to identify the secondary objects:Distance - N
    Select the input image:FITC
    Select the thresholding method:Otsu PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:1
    Regularization factor:0.05
    Name the outline image:Cells_GreenOutlines
    Manual threshold:0.0
    Select binary image:None
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

IdentifySecondaryObjects:[module_num:6|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Green_Ext
    Select the method to identify the secondary objects:Distance - N
    Select the input image:FITC
    Select the thresholding method:Otsu PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:8
    Regularization factor:0.05
    Name the outline image:Cells_GreenOutlines
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
    Fill holes in identified objects?:No

IdentifyTertiaryObjects:[module_num:7|svn_version:\'10300\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the larger identified objects:Cells_Green_Ext
    Select the smaller identified objects:Cells_Green
    Name the tertiary objects to be identified:DirectBackgroundGreen
    Name the outline image:CytoplasmOutlines
    Retain outlines of the tertiary objects?:No

IdentifySecondaryObjects:[module_num:8|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Red
    Select the method to identify the secondary objects:Distance - N
    Select the input image:PI
    Select the thresholding method:Otsu PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:1
    Regularization factor:0.05
    Name the outline image:Cells_RedOutlines
    Manual threshold:0.0
    Select binary image:None
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

IdentifySecondaryObjects:[module_num:9|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Red_Ext
    Select the method to identify the secondary objects:Distance - N
    Select the input image:PI
    Select the thresholding method:Otsu PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:8
    Regularization factor:0.05
    Name the outline image:Cells_RedOutlines
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
    Fill holes in identified objects?:No

IdentifyTertiaryObjects:[module_num:10|svn_version:\'10300\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the larger identified objects:Cells_Red_Ext
    Select the smaller identified objects:Cells_Red
    Name the tertiary objects to be identified:DirectBackgroundRed
    Name the outline image:CytoplasmOutlines
    Retain outlines of the tertiary objects?:No

MeasureObjectIntensity:[module_num:11|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:FITC
    Select objects to measure:Cells_Green
    Select objects to measure:DirectBackgroundGreen

MeasureObjectIntensity:[module_num:12|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:PI
    Select objects to measure:Cells_Red
    Select objects to measure:DirectBackgroundRed

CalculateMath:[module_num:13|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\'Mean + 2*SD\'\x5D]
    Name the output measurement:ThresholdDirectBackgroundGreen
    Operation:Add
    Select the first operand measurement type:Object
    Select the first operand objects:DirectBackgroundGreen
    Select the first operand measurement:Intensity_StdIntensity_FITC
    Multiply the above operand by:2
    Raise the power of above operand by:1
    Select the second operand measurement type:Object
    Select the second operand objects:DirectBackgroundGreen
    Select the second operand measurement:Intensity_MeanIntensity_FITC
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:14|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:ThresholdDirectBackgroundRed
    Operation:Add
    Select the first operand measurement type:Object
    Select the first operand objects:DirectBackgroundRed
    Select the first operand measurement:Intensity_StdIntensity_PI
    Multiply the above operand by:2
    Raise the power of above operand by:1
    Select the second operand measurement type:Object
    Select the second operand objects:DirectBackgroundRed
    Select the second operand measurement:Intensity_MeanIntensity_PI
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

RelateObjects:[module_num:15|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:Cells_Green
    Select the input parent objects:DirectBackgroundGreen
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:16|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:Cells_Red
    Select the input parent objects:DirectBackgroundRed
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

ClassifyObjects:[module_num:17|svn_version:\'10720\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Should each classification decision be based on a single measurement or on the combination of a pair of measurements?:Pair of measurements
    Hidden:1
    Select the object to be classified:DirectBackground
    Select the measurement to classify by:Math_ThresholdDirectBackground
    Select bin spacing:Evenly spaced bins
    Number of bins:2
    Lower threshold:0
    Use a bin for objects below the threshold?:No
    Upper threshold:1
    Use a bin for objects above the threshold?:No
    Enter the custom thresholds separating the values between bins:0,1
    Give each bin a name?:Yes
    Enter the bin names separated by commas:Negative,Positive
    Retain an image of the objects classified by their measurements, for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the output image:ClassifiedNuclei
    Enter the object name:DirectBackgroundGreen
    Select the first measurement:Math_ThresholdDirectBackgroundGreen
    Method to select the cutoff:Mean
    Enter the cutoff value:0.5
    Select the second measurement:Mean_Cells_Green_Intensity_MeanIntensity_FITC
    Method to select the cutoff:Mean
    Enter the cutoff value:0.5
    Use custom names for the bins?:Yes
    Enter the low-low bin name:GREEN_low_low
    Enter the low-high bin name:GREEN_ow_high
    Enter the high-low bin name:GREEN_high_low
    Enter the high-high bin name:GREEN_high_high
    Retain an image of the objects classified by their measurements, for use later in the pipeline (for example, in SaveImages)?:Yes
    Enter the image name:ClassifiedNucleiGreen

ClassifyObjects:[module_num:18|svn_version:\'10720\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Should each classification decision be based on a single measurement or on the combination of a pair of measurements?:Pair of measurements
    Hidden:1
    Select the object to be classified:DirectBackground
    Select the measurement to classify by:Math_ThresholdDirectBackground
    Select bin spacing:Evenly spaced bins
    Number of bins:2
    Lower threshold:0
    Use a bin for objects below the threshold?:No
    Upper threshold:1
    Use a bin for objects above the threshold?:No
    Enter the custom thresholds separating the values between bins:0,1
    Give each bin a name?:Yes
    Enter the bin names separated by commas:Negative,Positive
    Retain an image of the objects classified by their measurements, for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the output image:ClassifiedNuclei
    Enter the object name:DirectBackgroundRed
    Select the first measurement:Math_ThresholdDirectBackgroundRed
    Method to select the cutoff:Mean
    Enter the cutoff value:0.5
    Select the second measurement:Mean_Cells_Red_Intensity_MeanIntensity_PI
    Method to select the cutoff:Mean
    Enter the cutoff value:0.5
    Use custom names for the bins?:Yes
    Enter the low-low bin name:RED_low_low
    Enter the low-high bin name:RED_low_high
    Enter the high-low bin name:RED_high_low
    Enter the high-high bin name:RED_high_high
    Retain an image of the objects classified by their measurements, for use later in the pipeline (for example, in SaveImages)?:Yes
    Enter the image name:ClassifiedNucleiRed

GrayToColor:[module_num:19|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:PI
    Select the input image to be colored green:FITC
    Select the input image to be colored blue:DAPI
    Name the output image:RGB_merge
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

GrayToColor:[module_num:20|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:FITC
    Select the input image to be colored blue:DAPI
    Name the output image:FITCDAPI_merge
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

GrayToColor:[module_num:21|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:FITC
    Select the input image to be colored blue:Leave this black
    Name the output image:FITC_coloured
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

OverlayOutlines:[module_num:22|svn_version:\'10672\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:RGB_merge
    Name the output image:RGB_merge_outline
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:NucOutlines
    Select outline color:Blue
    Select outlines to display:Cells_GreenOutlines
    Select outline color:Green

OverlayOutlines:[module_num:23|svn_version:\'10672\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:FITC_coloured
    Name the output image:FITC_coloured_outline
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:NucOutlines
    Select outline color:White

SaveImages:[module_num:24|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:RGB_merge
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_MergeRGB
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7COutlines
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:25|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:FITC_coloured
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_FITC
    Select file format to use:png
    Output file location:Default Output Folder sub-folder\x7COutlines
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:26|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:DAPI
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_DAPI
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7COutlines
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:27|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:FITC_coloured_outline
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_FITC_outline
    Select file format to use:png
    Output file location:Default Output Folder sub-folder\x7COutlines
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:28|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:FITCDAPI_merge
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_MergeFITCDAPI
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7COutlines
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:29|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:ClassifiedNucleiGreen
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_ClassificationGreen
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7COutlines
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

ExportToSpreadsheet:[module_num:30|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B"Export any measurements to a comma-delimited file (.csv). The measurements made for the nuclei, cell and cytoplasm objects will be saved to separate .csv files, in addition to the per-image .csv\'s."\x5D]
    Select or enter the column delimiter:,
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
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CCount_Cells_Green,Image\x7CCount_Cells_Red,Image\x7CCount_ShrunkenRed,Image\x7CCount_FilteredGreenRedDouble,Image\x7CCount_Nuclei,Image\x7CCount_FilteredGreen,Image\x7CCount_FilteredRed,Image\x7CGroup_Index,Image\x7CGroup_Number,Image\x7CExecutionTime_06CorrectIlluminationApply,Image\x7CExecutionTime_10IdentifySecondaryObjects,Image\x7CExecutionTime_14CalculateMath,Image\x7CExecutionTime_13MeasureImageIntensity,Image\x7CExecutionTime_31SaveImages,Image\x7CExecutionTime_16ApplyThreshold,Image\x7CExecutionTime_02CorrectIlluminationCalculate,Image\x7CExecutionTime_12MaskImage,Image\x7CExecutionTime_11MaskImage,Image\x7CExecutionTime_03CorrectIlluminationCalculate,Image\x7CExecutionTime_17ApplyThreshold,Image\x7CExecutionTime_27CalculateMath,Image\x7CExecutionTime_28ExpandOrShrinkObjects,Image\x7CExecutionTime_18MeasureObjectIntensity,Image\x7CExecutionTime_09IdentifySecondaryObjects,Image\x7CExecutionTime_22FilterObjects,Image\x7CExecutionTime_05CorrectIlluminationApply,Image\x7CExecutionTime_15CalculateMath,Image\x7CExecutionTime_25GrayToColor,Image\x7CExecutionTime_24FilterObjects,Image\x7CExecutionTime_29OverlayOutlines,Image\x7CExecutionTime_21FilterObjects,Image\x7CExecutionTime_20ConserveMemory,Image\x7CExecutionTime_19MeasureObjectIntensity,Image\x7CExecutionTime_07CorrectIlluminationApply,Image\x7CExecutionTime_26CalculateMath,Image\x7CExecutionTime_08IdentifyPrimaryObjects,Image\x7CExecutionTime_23RelateObjects,Image\x7CExecutionTime_30SaveImages,Image\x7CExecutionTime_01LoadImages,Image\x7CExecutionTime_04CorrectIlluminationCalculate,Image\x7CMD5Digest_DAPI,Image\x7CMD5Digest_FITC,Image\x7CMD5Digest_PI,Image\x7CFileName_DAPI,Image\x7CFileName_FITC,Image\x7CFileName_PI,Image\x7CScaling_DAPI,Image\x7CScaling_FITC,Image\x7CScaling_PI,Image\x7CModuleError_06CorrectIlluminationApply,Image\x7CModuleError_10IdentifySecondaryObjects,Image\x7CModuleError_14CalculateMath,Image\x7CModuleError_13MeasureImageIntensity,Image\x7CModuleError_31SaveImages,Image\x7CModuleError_16ApplyThreshold,Image\x7CModuleError_02CorrectIlluminationCalculate,Image\x7CModuleError_12MaskImage,Image\x7CModuleError_11MaskImage,Image\x7CModuleError_03CorrectIlluminationCalculate,Image\x7CModuleError_17ApplyThreshold,Image\x7CModuleError_27CalculateMath,Image\x7CModuleError_28ExpandOrShrinkObjects,Image\x7CModuleError_18MeasureObjectIntensity,Image\x7CModuleError_09IdentifySecondaryObjects,Image\x7CModuleError_22FilterObjects,Image\x7CModuleError_05CorrectIlluminationApply,Image\x7CModuleError_15CalculateMath,Image\x7CModuleError_25GrayToColor,Image\x7CModuleError_24FilterObjects,Image\x7CModuleError_29OverlayOutlines,Image\x7CModuleError_21FilterObjects,Image\x7CModuleError_20ConserveMemory,Image\x7CModuleError_19MeasureObjectIntensity,Image\x7CModuleError_07CorrectIlluminationApply,Image\x7CModuleError_26CalculateMath,Image\x7CModuleError_08IdentifyPrimaryObjects,Image\x7CModuleError_23RelateObjects,Image\x7CModuleError_30SaveImages,Image\x7CModuleError_01LoadImages,Image\x7CModuleError_04CorrectIlluminationCalculate,Image\x7CIntensity_MinIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_MinIntensity_MaskRed_Cells_Red,Image\x7CIntensity_StdIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_StdIntensity_MaskRed_Cells_Red,Image\x7CIntensity_TotalIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_TotalIntensity_MaskRed_Cells_Red,Image\x7CIntensity_TotalArea_MaskGreen_Cells_Green,Image\x7CIntensity_TotalArea_MaskRed_Cells_Red,Image\x7CIntensity_MADIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_MADIntensity_MaskRed_Cells_Red,Image\x7CIntensity_MeanIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_MeanIntensity_MaskRed_Cells_Red,Image\x7CIntensity_MaxIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_MaxIntensity_MaskRed_Cells_Red,Image\x7CIntensity_MedianIntensity_MaskGreen_Cells_Green,Image\x7CIntensity_MedianIntensity_MaskRed_Cells_Red,Image\x7CIntensity_PercentMaximal_MaskGreen_Cells_Green,Image\x7CIntensity_PercentMaximal_MaskRed_Cells_Red,Image\x7CPathName_DAPI,Image\x7CPathName_FITC,Image\x7CPathName_PI,Image\x7CThreshold_OrigThreshold_ThreshGreen,Image\x7CThreshold_OrigThreshold_Nuclei,Image\x7CThreshold_OrigThreshold_ThreshRed,Image\x7CThreshold_SumOfEntropies_ThreshGreen,Image\x7CThreshold_SumOfEntropies_Nuclei,Image\x7CThreshold_SumOfEntropies_ThreshRed,Image\x7CThreshold_WeightedVariance_ThreshGreen,Image\x7CThreshold_WeightedVariance_Nuclei,Image\x7CThreshold_WeightedVariance_ThreshRed,Image\x7CThreshold_FinalThreshold_ThreshGreen,Image\x7CThreshold_FinalThreshold_Nuclei,Image\x7CThreshold_FinalThreshold_ThreshRed,Image\x7CMath_Math_Green,Image\x7CMath_Math_Red,FilteredGreenRedDouble\x7CMath_RedOnlyCount,FilteredGreenRedDouble\x7CMath_GreenOnlyCount,FilteredGreenRedDouble\x7CLocation_Center_Y,FilteredGreenRedDouble\x7CLocation_Center_X,FilteredGreenRedDouble\x7CParent_FilteredGreen,FilteredGreenRedDouble\x7CNumber_Object_Number,Nuclei\x7CLocation_Center_Y,Nuclei\x7CLocation_Center_X,Nuclei\x7CNumber_Object_Number,FilteredGreen\x7CParent_Cells_Green,FilteredGreen\x7CNumber_Object_Number,FilteredGreen\x7CLocation_Center_Y,FilteredGreen\x7CLocation_Center_X,FilteredGreen\x7CMath_GreenOnlyCount,FilteredRed\x7CMath_RedOnlyCount,FilteredRed\x7CLocation_Center_Y,FilteredRed\x7CLocation_Center_X,FilteredRed\x7CParent_Cells_Red,FilteredRed\x7CParent_FilteredGreen,FilteredRed\x7CNumber_Object_Number
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:Image.csv
    Use the object name for the file name?:Yes
    Data to export:Nuclei
    Combine these object measurements with those of the previous object?:No
    File name:Result.csv
    Use the object name for the file name?:No
    Data to export:Cells_Green
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:Cells_Red
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:DirectBackgroundGreen
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:DirectBackgroundRed
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
