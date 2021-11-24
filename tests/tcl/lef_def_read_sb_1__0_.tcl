import_lib /workspaces/OpenPhySyn/tests/data/libraries/skywater130nm/sky130_fd_sc_hd__tt_025C_1v80.lib
import_lef /workspaces/OpenPhySyn/tests/data/libraries/skywater130nm/sky130_fd_sc_hd.lef
import_def /workspaces/OpenPhySyn/tests/data/designs/sb_1__0_/sb_1__0__icv_in_design.def

#import_lef /workspaces/OpenPhySyn/tests/data/designs/sb_1__0_/sb_1__0__icv_in_design.lef





# LEF Notes:

# 1) Cannot import 2 lefs, need to combine your .tlef and .clef into one lef
# Reading def invokes opendb through db_ object, steps in Opendb:

# 1) define reader
