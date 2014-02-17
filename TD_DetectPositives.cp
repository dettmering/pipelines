CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\'Load the images by matching files in the folder against the unique text pattern for each stain\x3A d0.tif for nuclei, d1.tif for the PH3 image, d2.tif for the cell stain image. The three images together comprise an image set.\'\x5D]
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
    Image count:4
    Text that these images have in common (case-sensitive):3.tif
    Position of this image in each group:d0.tif
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:(?P<Slice>.*)_(.*)_(.*)
    Type the regular expression that finds metadata in the subfolder path:(?P<Slice>.*)_(.*)_(.*)
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
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:(?P<Slice>.*)_(.*)_(.*)
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
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:(?P<Slice>.*)_(.*)_(.*)
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
    Text that these images have in common (case-sensitive):0.tif
    Position of this image in each group:4
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:(?P<Slice>.*)_(.*)_(.*)
    Type the regular expression that finds metadata in the subfolder path:(?P<Slice>.*)_(.*)_(.*)
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
    Calculate metrics for which images?:Select...
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:DIC
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

Smooth:[module_num:3|svn_version:\'10465\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:DIC
    Name the output image:DICSmooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:5.0
    Edge intensity difference:0.1

ImageMath:[module_num:4|svn_version:\'10718\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Invert
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:DICInverted
    Image or measurement?:Image
    Select the first image:DICSmooth
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

ApplyThreshold:[module_num:5|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
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

MeasureImageAreaOccupied:[module_num:6|svn_version:\'10563\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Measure the area occupied in a binary image, or in objects?:Binary Image
    Select objects to measure:None
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:DICThresholded

ConserveMemory:[module_num:7|svn_version:\'9401\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Specify which images?:Images to remove
    Select image to remove:DIC
    Select image to remove:DICInverted
    Select image to remove:DICSmooth

CorrectIlluminationCalculate:[module_num:8|svn_version:\'10458\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:DAPI
    Name the output image:IllumBlue
    Select how the illumination function is calculated:Background
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

CorrectIlluminationCalculate:[module_num:9|svn_version:\'10458\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescale aktivieren? Ueber alle Bilder gleich anwenden?\'\x5D]
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

CorrectIlluminationCalculate:[module_num:10|svn_version:\'10458\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescale aktivieren? Ueber alle Bilder gleich anwenden?\'\x5D]
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

CorrectIlluminationApply:[module_num:11|svn_version:\'10300\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:DAPI
    Name the output image:CorrBlue
    Select the illumination function:IllumBlue
    Select how the illumination function is applied:Divide

CorrectIlluminationApply:[module_num:12|svn_version:\'10300\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:FITC
    Name the output image:CorrGreen
    Select the illumination function:IllumGreen
    Select how the illumination function is applied:Divide

CorrectIlluminationApply:[module_num:13|svn_version:\'10300\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:PI
    Name the output image:CorrRed
    Select the illumination function:IllumRed
    Select how the illumination function is applied:Divide

IdentifyPrimaryObjects:[module_num:14|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\'Identify the nuclei from the nuclear stain image. Some manual adjustment of the smoothing filter size and maxima supression distance is required to optimize segmentation.\'\x5D]
    Select the input image:CorrBlue
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):6,30
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Adaptive
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

IdentifySecondaryObjects:[module_num:15|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Green
    Select the method to identify the secondary objects:Distance - B
    Select the input image:CorrGreen
    Select the thresholding method:Otsu PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:6
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
    Fill holes in identified objects?:Yes

IdentifySecondaryObjects:[module_num:16|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells_Red
    Select the method to identify the secondary objects:Distance - B
    Select the input image:CorrRed
    Select the thresholding method:Otsu PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:6
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
    Fill holes in identified objects?:Yes

MeasureImageIntensity:[module_num:17|svn_version:\'10816\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:CorrGreen
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:Cells_Green
    Select the image to measure:CorrRed
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:Cells_Red

CalculateMath:[module_num:18|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\'CV * mu * F + mu\', \'F= 15\'\x5D]
    Name the output measurement:Math_Green
    Operation:Add
    Select the first operand measurement type:Image
    Select the first operand objects:None
    Select the first operand measurement:Intensity_MedianIntensity_CorrGreen_Cells_Green
    Multiply the above operand by:1.5
    Raise the power of above operand by:1
    Select the second operand measurement type:Image
    Select the second operand objects:None
    Select the second operand measurement:Intensity_MedianIntensity_CorrGreen_Cells_Green
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:19|svn_version:\'10905\'|variable_revision_number:1|show_window:False|notes:\x5B\'CV * mu * F + mu\', \'F= 15\'\x5D]
    Name the output measurement:Math_Red
    Operation:Add
    Select the first operand measurement type:Image
    Select the first operand objects:None
    Select the first operand measurement:Intensity_MedianIntensity_CorrRed_Cells_Red
    Multiply the above operand by:1.5
    Raise the power of above operand by:1
    Select the second operand measurement type:Image
    Select the second operand objects:None
    Select the second operand measurement:Intensity_MedianIntensity_CorrRed_Cells_Red
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

ApplyThreshold:[module_num:20|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
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

ApplyThreshold:[module_num:21|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
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

MeasureObjectSizeShape:[module_num:22|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:Cells_Green
    Select objects to measure:Cells_Red
    Calculate the Zernike features?:No

MeasureObjectIntensity:[module_num:23|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:ThreshGreen
    Select objects to measure:Cells_Green

MeasureObjectIntensity:[module_num:24|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:ThreshRed
    Select objects to measure:Cells_Red

ConserveMemory:[module_num:25|svn_version:\'9401\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Specify which images?:Images to remove
    Select image to remove:IllumBlue
    Select image to remove:IllumGreen
    Select image to remove:IllumRed
    Select image to remove:CorrBlue
    Select image to remove:CorrGreen
    Select image to remove:CorrRed

FilterObjects:[module_num:26|svn_version:\'10300\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:FilteredGreen
    Select the object to filter:Cells_Green
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:Nuclei
    Retain outlines of the identified objects?:Yes
    Name the outline image:FilteredGreenObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:Intensity_MeanIntensity_ThreshGreen
    Filter using a minimum measurement value?:Yes
    Minimum value:0.0001
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:10
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:27|svn_version:\'10300\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:FilteredRed
    Select the object to filter:Cells_Red
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:Nuclei
    Retain outlines of the identified objects?:Yes
    Name the outline image:FilteredRedObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:Intensity_MeanIntensity_ThreshRed
    Filter using a minimum measurement value?:Yes
    Minimum value:0.0001
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:10
    Filter using a maximum measurement value?:No
    Maximum value:1

RelateObjects:[module_num:28|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:FilteredRed
    Select the input parent objects:FilteredGreen
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:No
    Calculate distances to other parents?:No
    Parent name:None

FilterObjects:[module_num:29|svn_version:\'10300\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
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

RescaleIntensity:[module_num:30|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescales 4096 to 65536 grey values for export (x16)\'\x5D]
    Select the input image:DAPI
    Name the output image:RescaledBlue
    Select rescaling method:Choose specific values to be reset to a custom range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.0,16
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:31|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescales 4096 to 65536 grey values for export (x16)\'\x5D]
    Select the input image:FITC
    Name the output image:RescaledGreen
    Select rescaling method:Choose specific values to be reset to a custom range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.0,16
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:32|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescales 4096 to 65536 grey values for export (x16)\'\x5D]
    Select the input image:PI
    Name the output image:RescaledRed
    Select rescaling method:Choose specific values to be reset to a custom range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.0,16
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

GrayToColor:[module_num:33|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:RescaledRed
    Select the input image to be colored green:RescaledGreen
    Select the input image to be colored blue:RescaledBlue
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

OverlayOutlines:[module_num:34|svn_version:\'10672\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:ColorImage
    Name the output image:OrigOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:FilteredGreenObjects
    Select outline color:Green
    Select outlines to display:FilteredRedObjects
    Select outline color:Red
    Select outlines to display:NucOutlines
    Select outline color:Blue

SaveImages:[module_num:35|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:ColorImage
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_MergeRGB
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7CImages
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:36|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:OrigOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DAPI
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_Outlined
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7CImages
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:37|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:DICThresholded
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:DIC
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:No
    Text to append to the image name:Outlined
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7CImages
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

ExportToSpreadsheet:[module_num:38|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B"Export any measurements to a comma-delimited file (.csv). The measurements made for the nuclei, cell and cytoplasm objects will be saved to separate .csv files, in addition to the per-image .csv\'s."\x5D]
    Select or enter the column delimiter:,
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:Yes
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
    Data to export:FilteredGreenRedDouble
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
