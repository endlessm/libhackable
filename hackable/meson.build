# Copyright (c) 2018 Endless Mobile, Inc.

version = configuration_data()
version.set('HACKABLE_MAJOR_VERSION', version_components[0])
version.set('HACKABLE_MINOR_VERSION', version_components[1])
version.set('HACKABLE_MICRO_VERSION', version_components[2])
version_h = configure_file(configuration: version,
    input: 'hackable-version.h.in', output: 'hackable-version.h')

gdbus_targets = gnome.gdbus_codegen('hackable-objects',
    '../data/com.endlessm.Hackable.xml',
    interface_prefix: 'com.endlessm.Hackable',
    namespace: 'Hackable',
    install_header: true,
    install_dir: join_paths(get_option('includedir'), api_name, 'hackable'))

installed_headers = [
    'hackable-errors.h',
    version_h
]
private_headers = [
]
sources = [
    gdbus_targets[0],
    gdbus_targets[1],
    'hackable-errors.c'
]

include = include_directories('.')

main_library = shared_library('@0@-@1@'.format(meson.project_name(), api_version),
    sources, installed_headers, private_headers,
    c_args: ['-DG_LOG_DOMAIN="@0@"'.format(namespace_name),
        '-DCOMPILING_HACKABLE'],
    dependencies: [gio, gio_unix, glib, gobject],
    include_directories: include, install: true,
    soversion: api_version, version: libtool_version)

introspection_sources = [
    sources,
    join_paths(meson.build_root(), 'hackable', 'hackable-objects.h'),
    installed_headers
]

gnome.generate_gir(main_library, extra_args: ['--warn-all', '--warn-error'],
    identifier_prefix: 'Hackable', include_directories: include,
    includes: ['Gio-2.0', 'GLib-2.0', 'GObject-2.0'],
    install: true, namespace: namespace_name, nsversion: api_version,
    sources: introspection_sources, symbol_prefix: 'hackable')

install_headers(installed_headers, subdir: api_name)
