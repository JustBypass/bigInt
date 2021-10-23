file(REMOVE_RECURSE
  "menus.lib"
  "menus.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/menus.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
