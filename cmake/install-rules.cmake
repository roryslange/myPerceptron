install(
    TARGETS perceptron_exe
    RUNTIME COMPONENT perceptron_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
