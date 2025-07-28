project('Lumina', 'cpp',
  version: '0.0.1',
  default_options: [
    'cpp_std=c++20',
    'warning_level=3',
    'buildtype=debugoptimized'
  ]
)

inc = include_directories('include')

src = [
    #--------vector files--------
    'src/vector/vector2.cpp',
    'src/vector/vector3.cpp',
    'src/vector/vector4.cpp',
    #--------matrix files--------
]

lumina_lib= library(
  'lumina',
  src,
  include_directories: inc,
  install: true,
)
