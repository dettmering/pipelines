pipelines: Tills beloved CellProfiler pipelines
================================================

* __NucleiCount:__ Detects nuclei in 20x Epi eyefield. Has to be adjusted for different purposes.
* __TD_DetectPositives:__ Identifies positive cells in two channels. Former TD_IdentifyMacrophages_PrimaryOtsuAdaptive_sigmamu.cp, optimized for lung tissue.
* __TD_FibrosisDIC:__ Detects pixels occupied by tissue. Used for fibrosis quantification.
* __AE_NucleiMeasure:__ Measures nuclei area. For EMT identification.
* __AE_NucTransloc_small:__ Experimental. Optimized for many small nuclei (A549 normal morphology)
* __AE_NucTransloc_large:__ Experimental. Optimized for large nuclei (A549 EMT morphology)
* __AG_Toluidineblue:__ Experimental pipeline for Toluidine blue quantification
* __InvertForPrinting:__ Inverts image background to white and keeps 
fluorescence color. From CP website.
