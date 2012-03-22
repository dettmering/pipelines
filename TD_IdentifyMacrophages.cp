CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:True|notes:\x5B\'Load the images by matching files in the folder against the unique text pattern for each stain\x3A d0.tif for nuclei, d1.tif for the PH3 image, d2.tif for the cell stain image. The three images together comprise an image set.\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Regular expressions
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Default Input Folder\x7C.
    Check image sets for missing or duplicate files?:No
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:3
    Text that these images have in common (case-sensitive):3.tif
    Position of this image in each group:d0.tif
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
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
    Text that these images have in common (case-sensitive):1.tif
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
    Text that these images have in common (case-sensitive):2.tif
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

CorrectIlluminationCalculate:[module_num:2|svn_version:\'10458\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Select the input image:DAPI
    Name the output image:IllumBlue
    Select how the illumination function is calculated:Background
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:Yes
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Gaussian Filter
    Method to calculate smoothing filter size:Automatic
    Approximate object size:10
    Smoothing filter size:10
    Retain the averaged image for use later in the pipeline (for example, in SaveImages)?:No
    Name the averaged image:IllumBlueAvg
    Retain the dilated image for use later in the pipeline (for example, in SaveImages)?:No
    Name the dilated image:IllumBlueDilated
    Automatically calculate spline parameters?:Yes
    Background mode:auto
    Number of spline points:5
    Background threshold:2
    Image resampling factor:2
    Maximum number of iterations:40
    Residual value for convergence:0.001

CorrectIlluminationCalculate:[module_num:3|svn_version:\'10458\'|variable_revision_number:2|show_window:True|notes:\x5B\'Rescale aktivieren? Ueber alle Bilder gleich anwenden?\'\x5D]
    Select the input image:FITC
    Name the output image:IllumGreen
    Select how the illumination function is calculated:Regular
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:Yes
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Fit Polynomial
    Method to calculate smoothing filter size:Automatic
    Approximate object size:10
    Smoothing filter size:10
    Retain the averaged image for use later in the pipeline (for example, in SaveImages)?:No
    Name the averaged image:IllumBlueAvg
    Retain the dilated image for use later in the pipeline (for example, in SaveImages)?:No
    Name the dilated image:IllumBlueDilated
    Automatically calculate spline parameters?:Yes
    Background mode:auto
    Number of spline points:5
    Background threshold:2
    Image resampling factor:2
    Maximum number of iterations:40
    Residual value for convergence:0.001

CorrectIlluminationCalculate:[module_num:4|svn_version:\'10458\'|variable_revision_number:2|show_window:True|notes:\x5B\'Rescale aktivieren? Ueber alle Bilder gleich anwenden?\'\x5D]
    Select the input image:PI
    Name the output image:IllumRed
    Select how the illumination function is calculated:Regular
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:Yes
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Fit Polynomial
    Method to calculate smoothing filter size:Automatic
    Approximate object size:10
    Smoothing filter size:10
    Retain the averaged image for use later in the pipeline (for example, in SaveImages)?:No
    Name the averaged image:IllumBlueAvg
    Retain the dilated image for use later in the pipeline (for example, in SaveImages)?:No
    Name the dilated image:IllumBlueDilated
    Automatically calculate spline parameters?:Yes
    Background mode:auto
    Number of spline points:5
    Background threshold:2
    Image resampling factor:2
    Maximum number of iterations:40
    Residual value for convergence:0.001

CorrectIlluminationApply:[module_num:5|svn_version:\'10300\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:DAPI
    Name the output image:CorrBlue
    Select the illumination function:IllumBlue
    Select how the illumination function is applied:Divide

CorrectIlluminationApply:[module_num:6|svn_version:\'10300\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:FITC
    Name the output image:CorrGreen
    Select the illumination function:IllumGreen
    Select how the illumination function is applied:Divide

CorrectIlluminationApply:[module_num:7|svn_version:\'10300\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:PI
    Name the output image:CorrRed
    Select the illumination function:IllumRed
    Select how the illumination function is applied:Divide

IdentifyPrimaryObjects:[module_num:8|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\'Identify the nuclei from the nuclear stain image. Some manual adjustment of the smoothing filter size and maxima supression distance is required to optimize segmentation.\'\x5D]
    Select the input image:CorrBlue
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):6,30
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.008,1.0
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

IdentifySecondaryObjects:[module_num:9|svn_version:\'10826\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Green
    Select the method to identify the secondary objects:Distance - N
    Select the input image:CorrGreen
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:6
    Regularization factor:0.05
    Name the outline image:GreenOutlines
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

IdentifySecondaryObjects:[module_num:10|svn_version:\'10826\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Red
    Select the method to identify the secondary objects:Distance - N
    Select the input image:CorrGreen
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:6
    Regularization factor:0.05
    Name the outline image:RedOutlines
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

MaskImage:[module_num:11|svn_version:\'10428\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:CorrGreen
    Name the output image:MaskGreen
    Use objects or an image as a mask?:Objects
    Select object for mask:Cells_Green
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:12|svn_version:\'10428\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:CorrRed
    Name the output image:MaskRed
    Use objects or an image as a mask?:Objects
    Select object for mask:Cells_Green
    Select image for mask:None
    Invert the mask?:No

MeasureImageIntensity:[module_num:13|svn_version:\'10816\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Select the image to measure:MaskGreen
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:Cells_Green
    Select the image to measure:MaskRed
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:Cells_Red

CalculateMath:[module_num:14|svn_version:\'10905\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Name the output measurement:Math_Green
    Operation:None
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MedianIntensity_MaskGreen_Cells_Green
    Multiply the above operand by:2.5
    Raise the power of above operand by:1
    Select the second operand measurement type:Image
    Select the second operand objects:None
    Select the second operand measurement:Intensity_MedianIntensity_MaskGreen_Cells_Green
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:15|svn_version:\'10905\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Name the output measurement:Math_Red
    Operation:None
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MedianIntensity_MaskRed_Cells_Red
    Multiply the above operand by:2.5
    Raise the power of above operand by:1
    Select the second operand measurement type:Image
    Select the second operand objects:None
    Select the second operand measurement:Intensity_MedianIntensity_MaskGreen_Cells_Green
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

ApplyThreshold:[module_num:16|svn_version:\'6746\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Select the input image:CorrGreen
    Name the output image:ThreshGreen
    Select the output image type:Grayscale
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Measurement
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:Math_Math_Green

ApplyThreshold:[module_num:17|svn_version:\'6746\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Select the input image:CorrRed
    Name the output image:ThreshRed
    Select the output image type:Grayscale
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Measurement
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:Math_Math_Red

MeasureObjectIntensity:[module_num:18|svn_version:\'10816\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:ThreshGreen
    Select objects to measure:Cells_Green

MeasureObjectIntensity:[module_num:19|svn_version:\'10816\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:ThreshRed
    Select objects to measure:Cells_Red

ConserveMemory:[module_num:20|svn_version:\'9401\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Specify which images?:Images to remove
    Select image to remove:IllumBlue
    Select image to remove:IllumGreen
    Select image to remove:IllumRed
    Select image to remove:MaskGreen
    Select image to remove:MaskRed
    Select image to remove:CorrBlue
    Select image to remove:CorrGreen
    Select image to remove:CorrRed

FilterObjects:[module_num:21|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredGreen
    Select the object to filter:Cells_Green
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:Nuclei
    Retain outlines of the identified objects?:Yes
    Name the outline image:FilteredGreenObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:Intensity_MeanIntensity_ThreshGreen
    Filter using a minimum measurement value?:Yes
    Minimum value:0.001
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:22|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredRed
    Select the object to filter:Cells_Red
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:Nuclei
    Retain outlines of the identified objects?:Yes
    Name the outline image:FilteredRedObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:Intensity_MeanIntensity_ThreshRed
    Filter using a minimum measurement value?:Yes
    Minimum value:0.001
    Filter using a maximum measurement value?:No
    Maximum value:1

RelateObjects:[module_num:23|svn_version:\'10300\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Select the input child objects:FilteredRed
    Select the input parent objects:FilteredGreen
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:No
    Calculate distances to other parents?:No
    Parent name:None

FilterObjects:[module_num:24|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredGreenRedDouble
    Select the object to filter:FilteredGreen
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:FilteredRed
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:Children_FilteredRed_Count
    Filter using a minimum measurement value?:Yes
    Minimum value:1
    Filter using a maximum measurement value?:No
    Maximum value:1

GrayToColor:[module_num:25|svn_version:\'10341\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:PI
    Select the input image to be colored green:FITC
    Select the input image to be colored blue:DAPI
    Name the output image:ColorImage
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

ExpandOrShrinkObjects:[module_num:26|svn_version:\'10830\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Select the input objects:FilteredRed
    Name the output objects:ShrunkenRed
    Select the operation:Shrink objects by a specified number of pixels
    Number of pixels by which to expand or shrink:1
    Fill holes in objects so that all objects shrink to a single point?:No
    Retain the outlines of the identified objects for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the outline image:ShrunkenRedOutlines

OverlayOutlines:[module_num:27|svn_version:\'10672\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:ColorImage
    Name the output image:OrigOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:FilteredGreenObjects
    Select outline color:Green
    Select outlines to display:ShrunkenRedOutlines
    Select outline color:Red
    Select outlines to display:NucOutlines
    Select outline color:Blue

SaveImages:[module_num:28|svn_version:\'10822\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:ColorImage
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_MergeRGB
    Select file format to use:png
    Output file location:Default Output Folder\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:29|svn_version:\'10822\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:OrigOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_Outlined
    Select file format to use:png
    Output file location:Default Output Folder\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:30|svn_version:\'10880\'|variable_revision_number:7|show_window:True|notes:\x5B"Export any measurements to a comma-delimited file (.csv). The measurements made for the nuclei, cell and cytoplasm objects will be saved to separate .csv files, in addition to the per-image .csv\'s."\x5D]
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
    Press button to select measurements to export:None\x7CNone
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
    Data to export:FilteredGreenRedDouble
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
