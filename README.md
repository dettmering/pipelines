hyperpipes: Tills beloved CellProfiler pipelines
================================================

* __TD_NucleiCount:__ Only detects Nuclei in 20x Epi eyefield
* __TD_DetectPositives:__ Identifies positive cells in two channels. Former TD_IdentifyMacrophages_PrimaryOtsuAdaptive_sigmamu.cp
* __TD_Fibrosis:__ Detects pixels occupied by tissue. Used for fibrosis quantification.
* __AE_NucleiMeasure:__ Measures nuclei area. For EMT identification.
* __AE_NucTransloc_small:__ Optimized for many small nuclei (A549 normal morphology)
* __AE_NucTransloc_large:__ Optimized for large nuclei (A549 EMT morphology)
* __InvertForPrinting:__ Inverts image background to white and keeps 
fluorescence color. From CP website.
* __FocusCheck:__ Checks whether images are in focus and flags those which are. Used if z-Stacks were taken to account for defocussing.
