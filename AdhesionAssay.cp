CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\'Loading images. Replace "common text" FITC for PI if necessary. In that case, leave the rest as FITC.\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Default Input Folder\x7CNone
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:Run
    Select subfolders to analyze:
    Image count:2
    Text that these images have in common (case-sensitive):Phako
    Position of this image in each group:1
    Extract metadata from where?:Path
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Phako
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):DAPI
    Position of this image in each group:2
    Extract metadata from where?:Path
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

CorrectIlluminationCalculate:[module_num:2|svn_version:\'10458\'|variable_revision_number:2|show_window:False|notes:\x5B\'Calculate illumination correction for PBL channel.\'\x5D]
    Select the input image:FITC
    Name the output image:IllumFITC
    Select how the illumination function is calculated:Regular
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:Yes
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Gaussian Filter
    Method to calculate smoothing filter size:Manually
    Approximate object size:10
    Smoothing filter size:20
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

CorrectIlluminationCalculate:[module_num:3|svn_version:\'10458\'|variable_revision_number:2|show_window:False|notes:\x5B\'Calculate illumination correction for phase contrast EC channel.\'\x5D]
    Select the input image:Phako
    Name the output image:IllumPhako
    Select how the illumination function is calculated:Regular
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:No
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Splines
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

CorrectIlluminationApply:[module_num:4|svn_version:\'10300\'|variable_revision_number:3|show_window:False|notes:\x5B\'Correct illumination for PBL.\'\x5D]
    Select the input image:FITC
    Name the output image:CorrFITC
    Select the illumination function:IllumFITC
    Select how the illumination function is applied:Divide

CorrectIlluminationApply:[module_num:5|svn_version:\'10300\'|variable_revision_number:3|show_window:False|notes:\x5B\'Collect illumination for EC. Divide produces grey image, subtract works.\'\x5D]
    Select the input image:Phako
    Name the output image:CorrPhako
    Select the illumination function:IllumPhako
    Select how the illumination function is applied:Subtract

EnhanceOrSuppressFeatures:[module_num:6|svn_version:\'10591\'|variable_revision_number:2|show_window:False|notes:\x5B\'Enhace dark holes in EC phase contrast image. Works well, is used to count EC.\'\x5D]
    Select the input image:CorrPhako
    Name the output image:FeaturePhako
    Select the operation:Enhance
    Feature size:10
    Feature type:Dark holes
    Range of hole sizes:5,30

ApplyThreshold:[module_num:7|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\'Apply threshold to extracted features. Needs to be done for cell detection to work.\'\x5D]
    Select the input image:FeaturePhako
    Name the output image:ThreshPhako
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Otsu Global
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1.5
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:8|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\'Detects EC from thresholded phase contrast image.\'\x5D]
    Select the input image:ThreshPhako
    Name the primary objects to be identified:EC_Phako
    Typical diameter of objects, in pixel units (Min,Max):5,40
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:ECOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:Yes
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

IdentifyPrimaryObjects:[module_num:9|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\'Detects EC from DAPI object size.\'\x5D]
    Select the input image:CorrFITC
    Name the primary objects to be identified:EC
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:Yes
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1.2
    Lower and upper bounds on threshold:0.000,1.0
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:30
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PBLOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Erase
    Maximum number of objects:300
    Select the measurement to threshold with:None

IdentifySecondaryObjects:[module_num:10|svn_version:\'10826\'|variable_revision_number:7|show_window:False|notes:\x5B\'Expands borders to find cell borders. Not very precise. Can be used to estimate stuck PBL per EC, but is not really needed.\'\x5D]
    Select the input objects:EC
    Name the objects to be identified:EC_Phako_expanded
    Select the method to identify the secondary objects:Distance - N
    Select the input image:CorrPhako
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:30
    Regularization factor:0.05
    Name the outline image:ECSecondaryOutlines
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

IdentifyPrimaryObjects:[module_num:11|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\'Identify PBL. Thresholding is done very simple by Otsu x 1.5, but should be optimized to mu + 2 sigma thresholding.\', \'Detects PBL from DAPI object size.\'\x5D]
    Select the input image:CorrFITC
    Name the primary objects to be identified:PBL
    Typical diameter of objects, in pixel units (Min,Max):2,9
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1.2
    Lower and upper bounds on threshold:0.000,1.0
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PBLOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Erase
    Maximum number of objects:300
    Select the measurement to threshold with:None

RelateObjects:[module_num:12|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\'How many PBL are on one EC?\'\x5D]
    Select the input child objects:PBL
    Select the input parent objects:EC_Phako_expanded
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:No
    Calculate distances to other parents?:No
    Parent name:None

MeasureObjectSizeShape:[module_num:13|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:EC
    Select objects to measure:EC_Phako_expanded
    Select objects to measure:PBL
    Calculate the Zernike features?:No

MeasureObjectIntensity:[module_num:14|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:CorrFITC
    Select objects to measure:EC
    Select objects to measure:PBL

ConserveMemory:[module_num:15|svn_version:\'9401\'|variable_revision_number:1|show_window:False|notes:\x5B\'Removes unneeded images.\'\x5D]
    Specify which images?:Images to remove
    Select image to remove:IllumFITC
    Select image to remove:IllumPhako
    Select image to remove:CorrPhako

OverlayOutlines:[module_num:16|svn_version:\'10672\'|variable_revision_number:2|show_window:False|notes:\x5B\'Generate output image\'\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:Phako
    Name the output image:PhakoOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:2
    Select outlines to display:ECOutlines
    Select outline color:Black
    Select outlines to display:PBLOutlines
    Select outline color:Green
    Select outlines to display:ECSecondaryOutlines
    Select outline color:White

GrayToColor:[module_num:17|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\'Generate output image\'\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:CorrFITC
    Select the input image to be colored blue:Phako
    Name the output image:ECPBLRaw
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

SaveImages:[module_num:18|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\'Save output image\'\x5D]
    Select the type of image to save:Image
    Select the image to save:PhakoOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:Phako
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_Outlines
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7CImages
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:19|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\'Save output image\'\x5D]
    Select the type of image to save:Image
    Select the image to save:ECPBLRaw
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:Phako
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_Overlay
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7CImages
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:Yes

SaveImages:[module_num:20|svn_version:\'10822\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:CorrFITC
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:Phako
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_PBLOverlay
    Select file format to use:jpg
    Output file location:Default Output Folder sub-folder\x7CImages
    Image bit depth:8
    Overwrite existing files without warning?:No
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gist_heat
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:Yes

FlagImage:[module_num:21|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\'Flags images in which a low EC number was detected. The adhesion assay requires a confluent EC monolayer. The number of 270 EC is based on initial tests and is 2 Stdevs lower than the mean EC count per 512 x 512 px phase contrast image.\'\x5D]
    Hidden:1
    Hidden:1
    Name the flag\'s category:Metadata
    Name the flag:LowECNumber
    Flag if any, or all, measurement(s) fails to meet the criteria?:Flag if any fail
    Skip image set if flagged?:No
    Flag is based on:Measurements for all objects in each image
    Select the object whose measurements will be used to flag:EC
    Which measurement?:Number_Object_Number
    Flag images based on low values?:Yes
    Minimum value:270
    Flag images based on high values?:No
    Maximum value:1

ExportToSpreadsheet:[module_num:22|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B\'Export data to spreadsheet\'\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:No
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:Yes
    Calculate the per-image standard deviation values for object measurements?:Yes
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
