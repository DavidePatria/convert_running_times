# build

create build dir in root and move there `mkdir build && cd build`
then `cmake .. && make`, this will also generate `compile_commands.json`
to execute, from the build dir `./convert distance time` where time is formatted as `hours:minutes:seconds`. do not omit seconds
