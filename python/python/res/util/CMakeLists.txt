set(PYTHON_SOURCES
    __init__.py
    log.py
    res_log.py
    ui_return.py
    res_version.py
    substitution_list.py
)

add_python_package("python.res.util"  ${PYTHON_INSTALL_PREFIX}/res/util "${PYTHON_SOURCES}" True)

add_subdirectory(enums)
