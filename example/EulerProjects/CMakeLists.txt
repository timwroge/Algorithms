set(targets 1 2 3)

foreach (target ${targets})
    set(ep_src "${target}.cc" )
    set(ep_headers  "${target}.hh" )
    add_executable("ep${target}" ${ep_src} ${ep_src})
endforeach(target) 
