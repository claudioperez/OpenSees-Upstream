#add_library(libg3 OBJECT)
add_subdirectory(domain)
add_subdirectory(damage)
add_subdirectory(actor)
add_subdirectory(analysis)
add_subdirectory(convergenceTest)
add_subdirectory(coordTransformation)
add_subdirectory(graph)
add_subdirectory(handler)
#add_subdirectory(element)
add_subdirectory(material)
add_subdirectory(matrix)
add_subdirectory(recorder)
add_subdirectory(tagged)
add_subdirectory(utility)
add_subdirectory(base)
add_subdirectory(system_of_eqn)

#target_link_libraries(libg3
#    OBJECT
#	domain
#	damage
#	actor
#	analysis
#	convergenceTest
#	coordTransformation
#	graph
#	handler
#	matrix
#	recorder
#	tagged
#	utility
#	#base
#)
#set_target_properties(libg3 PROPERTIES LINK_FLAGS "-Wl,--whole-archive")

#
#add_subdirectory(utility)



