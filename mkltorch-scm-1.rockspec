package = "mkltorch"
version = "scm-1"

source = {
   url = "git://github.com/MlWoo/mkltorch.git",
}

description = {
   summary = "Wrapper of mklnn library Implementation",
   detailed = [[
   ]],
   homepage = "https://github.com/MlWoo/mkltorch",
   license = "BSD"
}

dependencies = {
   "torch >= 7.0",
}

build = {
   type = "command",
   build_command = [[

jopts=$(getconf _NPROCESSORS_CONF)

echo "Building on $jopts cores"
cmake -E make_directory build && cd build && cmake .. -DLUALIB=$(LUALIB) -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS} -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="$(LUA_BINDIR)/.." -DCMAKE_INSTALL_PREFIX="$(PREFIX)" && $(MAKE) -j$jopts install
]],
	platforms = {
      windows = {
   build_command = [[
cmake -E make_directory build && cd build && cmake .. -DLUALIB=$(LUALIB) -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="$(LUA_BINDIR)/.." -DCMAKE_INSTALL_PREFIX="$(PREFIX)" && $(MAKE) install
]]
	  }
   },
   install_command = "cd build"
}
