# VC.Undersoft.Submix.Release
Low latency alghoritm to select hashtable index from key. 
Library VC.Undersoft.Submix contains assmebly methods for bit scan and map key in to index avoiding divide remeinder (modulo %) which is most expensive and can cost 80 clocks for operation. Presented alghoritm costs 8 - 60 depending on size of hashtable. This alghoritm is directed to tables with size above 2048 elements.
