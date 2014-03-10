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
    Calculate metrics for which images?:All loaded images
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:DAPI
    Include the image rescaling value?:Yes
    Calculate blur metrics?:Yes
    Spatial scale for blur measurements:20
    Calculate saturation metrics?:Yes
    Calculate intensity metrics?:Yes
    Calculate thresholds?:No
    Use all thresholding methods?:No
    Select a thresholding method:Otsu Global
    Typical fraction of the image covered by objects:0.1
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground

ExportToSpreadsheet:[module_num:3|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B"Export any measurements to a comma-delimited file (.csv). The measurements made for the nuclei, cell and cytoplasm objects will be saved to separate .csv files, in addition to the per-image .csv\'s."\x5D]
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
    Press button to select measurements to export:Image\x7CImageQuality_LocalFocusScore_DAPI_20,Image\x7CImageQuality_LocalFocusScore_FITC_20,Image\x7CImageQuality_LocalFocusScore_PI_20,Image\x7CImageQuality_LocalFocusScore_DIC_20,Image\x7CImageQuality_MinIntensity_DAPI,Image\x7CImageQuality_MinIntensity_FITC,Image\x7CImageQuality_MinIntensity_PI,Image\x7CImageQuality_MinIntensity_DIC,Image\x7CImageQuality_StdIntensity_DAPI,Image\x7CImageQuality_StdIntensity_FITC,Image\x7CImageQuality_StdIntensity_PI,Image\x7CImageQuality_StdIntensity_DIC,Image\x7CImageQuality_TotalIntensity_DAPI,Image\x7CImageQuality_TotalIntensity_FITC,Image\x7CImageQuality_TotalIntensity_PI,Image\x7CImageQuality_TotalIntensity_DIC,Image\x7CImageQuality_TotalArea_DAPI,Image\x7CImageQuality_TotalArea_FITC,Image\x7CImageQuality_TotalArea_PI,Image\x7CImageQuality_TotalArea_DIC,Image\x7CImageQuality_PowerLogLogSlope_DAPI,Image\x7CImageQuality_PowerLogLogSlope_FITC,Image\x7CImageQuality_PowerLogLogSlope_PI,Image\x7CImageQuality_PowerLogLogSlope_DIC,Image\x7CImageQuality_MADIntensity_DAPI,Image\x7CImageQuality_MADIntensity_FITC,Image\x7CImageQuality_MADIntensity_PI,Image\x7CImageQuality_MADIntensity_DIC,Image\x7CImageQuality_MeanIntensity_DAPI,Image\x7CImageQuality_MeanIntensity_FITC,Image\x7CImageQuality_MeanIntensity_PI,Image\x7CImageQuality_MeanIntensity_DIC,Image\x7CImageQuality_Scaling_DAPI,Image\x7CImageQuality_Scaling_FITC,Image\x7CImageQuality_Scaling_PI,Image\x7CImageQuality_Scaling_DIC,Image\x7CImageQuality_PercentMinimal_DAPI,Image\x7CImageQuality_PercentMinimal_FITC,Image\x7CImageQuality_PercentMinimal_PI,Image\x7CImageQuality_PercentMinimal_DIC,Image\x7CImageQuality_FocusScore_DAPI,Image\x7CImageQuality_FocusScore_FITC,Image\x7CImageQuality_FocusScore_PI,Image\x7CImageQuality_FocusScore_DIC,Image\x7CImageQuality_Correlation_DAPI_20,Image\x7CImageQuality_Correlation_FITC_20,Image\x7CImageQuality_Correlation_PI_20,Image\x7CImageQuality_Correlation_DIC_20,Image\x7CImageQuality_MaxIntensity_DAPI,Image\x7CImageQuality_MaxIntensity_FITC,Image\x7CImageQuality_MaxIntensity_PI,Image\x7CImageQuality_MaxIntensity_DIC,Image\x7CImageQuality_MedianIntensity_DAPI,Image\x7CImageQuality_MedianIntensity_FITC,Image\x7CImageQuality_MedianIntensity_PI,Image\x7CImageQuality_MedianIntensity_DIC,Image\x7CImageQuality_PercentMaximal_DAPI,Image\x7CImageQuality_PercentMaximal_FITC,Image\x7CImageQuality_PercentMaximal_PI,Image\x7CImageQuality_PercentMaximal_DIC,Image\x7CExecutionTime_02MeasureImageQuality,Image\x7CExecutionTime_01LoadImages,Image\x7CMD5Digest_DAPI,Image\x7CMD5Digest_FITC,Image\x7CMD5Digest_PI,Image\x7CMD5Digest_DIC,Image\x7CFileName_DAPI,Image\x7CFileName_FITC,Image\x7CFileName_PI,Image\x7CFileName_DIC,Image\x7CScaling_DAPI,Image\x7CScaling_FITC,Image\x7CScaling_PI,Image\x7CScaling_DIC,Image\x7CModuleError_02MeasureImageQuality,Image\x7CModuleError_01LoadImages,Image\x7CPathName_DAPI,Image\x7CPathName_FITC,Image\x7CPathName_PI,Image\x7CPathName_DIC,Image\x7CGroup_Index,Image\x7CGroup_Number,Image\x7CMetadata_Slice
