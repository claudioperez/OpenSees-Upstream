add_library(libg3 SHARED)
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

target_link_libraries(libg3
    PUBLIC
	domain
	damage
	actor
	analysis
	convergenceTest
	coordTransformation
	graph
	handler

	matrix
	recorder
	tagged
	utility
	base
)

#
#add_subdirectory(utility)



