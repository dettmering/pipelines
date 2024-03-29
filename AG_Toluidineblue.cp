CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
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
    Text that these images have in common (case-sensitive):.JPG
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:InputImage
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:No

Resize:[module_num:2|svn_version:\'10627\'|variable_revision_number:4|show_window:False|notes:\x5B\'Not resizing and removing the original afterwards will result in a MemoryError.\'\x5D]
    Select the input image:InputImage
    Name the output image:ResizedInput
    Select resizing method:Resize by a fraction or multiple of the original size
    Resizing factor:0.4
    Width of the final image, in pixels:100
    Height of the final image, in pixels:100
    Interpolation method:Nearest Neighbor
    How do you want to specify the dimensions?:Manual
    Select the image with the desired dimensions:None
    Additional image count:0

ColorToGray:[module_num:3|svn_version:\'10318\'|variable_revision_number:2|show_window:False|notes:\x5B\'Splits RGB file, deletes red and blue channels and performs OTSU to generate black white image.\'\x5D]
    Select the input image:ResizedInput
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

ConserveMemory:[module_num:4|svn_version:\'9401\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Specify which images?:Images to remove
    Select image to remove:InputImage
    Select image to remove:OrigRed
    Select image to remove:ResizedInput

CorrectIlluminationCalculate:[module_num:5|svn_version:\'10458\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:OrigBlue
    Name the output image:IllumBlue
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

CorrectIlluminationApply:[module_num:6|svn_version:\'10300\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:OrigBlue
    Name the output image:CorrBlue
    Select the illumination function:IllumBlue
    Select how the illumination function is applied:Divide
    Select the input image:OrigGreen
    Name the output image:CorrGreen
    Select the illumination function:IllumBlue
    Select how the illumination function is applied:Divide

ImageMath:[module_num:7|svn_version:\'10718\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Subtract
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:ImageAfterMath
    Image or measurement?:Image
    Select the first image:CorrBlue
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:CorrGreen
    Multiply the second image by:1.2
    Measurement:

RescaleIntensity:[module_num:8|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:ImageAfterMath
    Name the output image:Rescaled
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

ApplyThreshold:[module_num:9|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:Rescaled
    Name the output image:ThreshBlue
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Otsu Global
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.5
    Select the input objects:None
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Select the measurement to threshold with:None

MeasureImageAreaOccupied:[module_num:10|svn_version:\'10563\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Measure the area occupied in a binary image, or in objects?:Binary Image
    Select objects to measure:None
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:ThreshBlue

SaveImages:[module_num:11|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:ThreshBlue
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:InputImage
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_filtered
    Select file format to use:jpg
    Output file location:Default Output Folder\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:12|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder\x7CNone
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:Yes
    Press button to select measurements to export:Image\x7CAreaOccupied_TotalArea_ThreshBlue,Image\x7CAreaOccupied_AreaOccupied_ThreshBlue,Image\x7CFileName_InputImage,Image\x7CThreshold_OrigThreshold_ThreshBlue,Image\x7CThreshold_SumOfEntropies_ThreshBlue,Image\x7CThreshold_WeightedVariance_ThreshBlue,Image\x7CThreshold_FinalThreshold_ThreshBlue
    Data to export:Do not use
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
