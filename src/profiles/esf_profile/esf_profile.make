; esf_profile make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Modules +++++

projects[admin_views][version] = "1.2"
projects[admin_views][subdir] = "contrib"

projects[ctools][version] = "1.3"
projects[ctools][subdir] = "contrib"

projects[context][version] = "3.1"
projects[context][subdir] = "contrib"

projects[context_omega][version] = "1.1"
projects[context_omega][subdir] = "contrib"

projects[profiler_builder][version] = "1.0"
projects[profiler_builder][subdir] = "contrib"

projects[eck][version] = "2.0-rc2"
projects[eck][subdir] = "contrib"

projects[features][version] = "2.0"
projects[features][subdir] = "contrib"

projects[features_extra][version] = "1.x-dev"
projects[features_extra][subdir] = "contrib"

projects[bundle_copy][version] = "1.1"
projects[bundle_copy][subdir] = "contrib"

projects[email][version] = "1.2"
projects[email][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[field_group][version] = "1.3"
projects[field_group][subdir] = "contrib"

projects[filefield_paths][version] = "1.0-beta4"
projects[filefield_paths][subdir] = "contrib"

projects[inline_entity_form][version] = "1.3"
projects[inline_entity_form][subdir] = "contrib"

projects[link][version] = "1.2"
projects[link][subdir] = "contrib"

projects[password_field][version] = "1.0-beta1"
projects[password_field][subdir] = "contrib"

projects[references][version] = "2.1"
projects[references][subdir] = "contrib"

projects[viewfield][version] = "2.0"
projects[viewfield][subdir] = "contrib"

projects[file_entity][version] = "2.0-alpha3"
projects[file_entity][subdir] = "contrib"

projects[imce][version] = "1.8"
projects[imce][subdir] = "contrib"

projects[media][version] = "2.0-alpha3"
projects[media][subdir] = "contrib"

projects[l10n_client][version] = "1.3"
projects[l10n_client][subdir] = "contrib"

projects[l10n_update][version] = "1.0-beta3"
projects[l10n_update][subdir] = "contrib"

projects[i18n][version] = "1.10"
projects[i18n][subdir] = "contrib"

projects[translation_table][version] = "1.0-beta1"
projects[translation_table][subdir] = "contrib"

projects[backup_migrate][version] = "2.8"
projects[backup_migrate][subdir] = "contrib"

projects[breakpoints][version] = "1.1"
projects[breakpoints][subdir] = "contrib"

projects[db_maintenance][version] = "1.1"
projects[db_maintenance][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity][version] = "1.2"
projects[entity][subdir] = "contrib"

projects[entityreference_views_formatter][version] = "1.x-dev"
projects[entityreference_views_formatter][subdir] = "contrib"

projects[libraries][version] = "2.1"
projects[libraries][subdir] = "contrib"

projects[menu_block][version] = "2.3"
projects[menu_block][subdir] = "contrib"

projects[module_filter][version] = "1.8"
projects[module_filter][subdir] = "contrib"

projects[navbar][version] = "1.0-beta1"
projects[navbar][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

projects[pdm][version] = "1.0"
projects[pdm][subdir] = "contrib"

projects[quicktabs][version] = "3.6"
projects[quicktabs][subdir] = "contrib"

projects[simplified_menu_admin][version] = "1.0-beta2"
projects[simplified_menu_admin][subdir] = "contrib"

projects[site_map][version] = "1.0"
projects[site_map][subdir] = "contrib"

projects[taxonomy_breadcrumb][version] = "1.x-dev"
projects[taxonomy_breadcrumb][subdir] = "contrib"

projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

projects[transliteration][version] = "3.1"
projects[transliteration][subdir] = "contrib"

projects[weight][version] = "2.3"
projects[weight][subdir] = "contrib"

projects[uuid][version] = "1.0-alpha5"
projects[uuid][subdir] = "contrib"

projects[ckeditor][version] = "1.13"
projects[ckeditor][subdir] = "contrib"

projects[imce_wysiwyg][version] = "1.0"
projects[imce_wysiwyg][subdir] = "contrib"

projects[jquery_update][version] = "2.3"
projects[jquery_update][subdir] = "contrib"

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][subdir] = "contrib"

projects[variable][version] = "2.3"
projects[variable][subdir] = "contrib"

projects[views][version] = "3.7"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.2"
projects[views_bulk_operations][subdir] = "contrib"

projects[workbench][version] = "1.2"
projects[workbench][subdir] = "contrib"

projects[workbench_media][version] = "2.1"
projects[workbench_media][subdir] = "contrib"

; +++++ Themes +++++

; ember
projects[ember][type] = "theme"
projects[ember][version] = "2.x-dev"
projects[ember][subdir] = "contrib"

; omega
projects[omega][type] = "theme"
projects[omega][version] = "4.1"
projects[omega][subdir] = "contrib"

; +++++ Libraries +++++

; CKEditor
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][type] = "library"
libraries[ckeditor][destination] = "libraries"
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.6.1/ckeditor_3.6.6.1.tar.gz"

; +++++ Patches +++++

projects[eck][patch][] = "http://drupal.org/files/0001-eck-issue-1681636-Installation-SQL-error-Duplicate-P.patch"
projects[l10n_update][patch][] = "https://drupal.org/files/1567372-11-l10n_update-integrity-constraint-on-install.patch"