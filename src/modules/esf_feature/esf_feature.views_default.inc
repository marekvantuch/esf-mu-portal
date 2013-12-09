<?php
/**
 * @file
 * esf_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function esf_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jokes';
  $view->description = '';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'Jokes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Jokes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Globální: Náhodný */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'joke' => 'joke',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Jokes';
  $translatables['jokes'] = array(
    t('Master'),
    t('Jokes'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Block'),
  );
  $export['jokes'] = $view;

  $view = new view();
  $view->name = 'legal_subjects';
  $view->description = '';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'Legal Subjects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Váha: Váha */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Obsah: Nadpis */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'legal_subject' => 'legal_subject',
  );
  $translatables['legal_subjects'] = array(
    t('Master'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
  );
  $export['legal_subjects'] = $view;

  $view = new view();
  $view->name = 'news';
  $view->description = 'Displaying news in various lists';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Novinka';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Položek na stránku';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Vše -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Vynechat položky';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« první';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ předchozí';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'následující ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'poslední »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Obsah: Datum vytvoření */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'news';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['block_description'] = 'Novinka';
  $translatables['news'] = array(
    t('Master'),
    t('Novinka'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Položek na stránku'),
    t('- Vše -'),
    t('Vynechat položky'),
    t('« první'),
    t('‹ předchozí'),
    t('následující ›'),
    t('poslední »'),
    t('Page'),
    t('Block'),
  );
  $export['news'] = $view;

  $view = new view();
  $view->name = 'reference_law_to_legal_subject';
  $view->description = 'Table displaying laws related to one legal subject';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'Reference: Law to Legal Subject';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Položek na stránku';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Vše -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Vynechat položky';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« první';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ předchozí';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'následující ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'poslední »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Vztah: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_laws_target_id']['id'] = 'field_laws_target_id';
  $handler->display->display_options['relationships']['field_laws_target_id']['table'] = 'field_data_field_laws';
  $handler->display->display_options['relationships']['field_laws_target_id']['field'] = 'field_laws_target_id';
  $handler->display->display_options['relationships']['field_laws_target_id']['label'] = 'Law';
  $handler->display->display_options['relationships']['field_laws_target_id']['required'] = TRUE;
  /* Pole: Law: Law type */
  $handler->display->display_options['fields']['field_law_type']['id'] = 'field_law_type';
  $handler->display->display_options['fields']['field_law_type']['table'] = 'field_data_field_law_type';
  $handler->display->display_options['fields']['field_law_type']['field'] = 'field_law_type';
  $handler->display->display_options['fields']['field_law_type']['relationship'] = 'field_laws_target_id';
  $handler->display->display_options['fields']['field_law_type']['label'] = 'Typ';
  $handler->display->display_options['fields']['field_law_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_law_type']['type'] = 'taxonomy_term_reference_plain';
  /* Pole: Law: Number */
  $handler->display->display_options['fields']['field_number']['id'] = 'field_number';
  $handler->display->display_options['fields']['field_number']['table'] = 'field_data_field_number';
  $handler->display->display_options['fields']['field_number']['field'] = 'field_number';
  $handler->display->display_options['fields']['field_number']['relationship'] = 'field_laws_target_id';
  $handler->display->display_options['fields']['field_number']['label'] = 'Číslo';
  $handler->display->display_options['fields']['field_number']['element_label_colon'] = FALSE;
  /* Pole: Law: ASPI */
  $handler->display->display_options['fields']['field_aspi']['id'] = 'field_aspi';
  $handler->display->display_options['fields']['field_aspi']['table'] = 'field_data_field_aspi';
  $handler->display->display_options['fields']['field_aspi']['field'] = 'field_aspi';
  $handler->display->display_options['fields']['field_aspi']['relationship'] = 'field_laws_target_id';
  /* Pole: Law: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_law';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_laws_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Nadpis';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Kontextový filtr: Obsah: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Vše';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'legal_subject' => 'legal_subject',
  );
  $translatables['reference_law_to_legal_subject'] = array(
    t('Master'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Položek na stránku'),
    t('- Vše -'),
    t('Vynechat položky'),
    t('« první'),
    t('‹ předchozí'),
    t('následující ›'),
    t('poslední »'),
    t('Law'),
    t('Typ'),
    t('Číslo'),
    t('ASPI'),
    t('Nadpis'),
    t('Vše'),
  );
  $export['reference_law_to_legal_subject'] = $view;

  $view = new view();
  $view->name = 'reference_legal_subject_to_school_subject';
  $view->description = 'Table displaying legal subjects related to one school subject';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'Reference: Legal Subject to School Subject';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Položek na stránku';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Vše -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Vynechat položky';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« první';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ předchozí';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'následující ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'poslední »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_code' => 'field_code',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Chování při žádných výsledcích: Globální: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'No Results';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'K tomuto předmětu se nevztahují žádné obory práva.';
  /* Vztah: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_school_subjects_node']['id'] = 'reverse_field_school_subjects_node';
  $handler->display->display_options['relationships']['reverse_field_school_subjects_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_school_subjects_node']['field'] = 'reverse_field_school_subjects_node';
  $handler->display->display_options['relationships']['reverse_field_school_subjects_node']['label'] = 'Legal Subject';
  $handler->display->display_options['relationships']['reverse_field_school_subjects_node']['required'] = TRUE;
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_school_subjects_node';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Pole: Obsah: Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'field_data_field_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['relationship'] = 'reverse_field_school_subjects_node';
  $handler->display->display_options['fields']['field_code']['label'] = 'Kód';
  $handler->display->display_options['fields']['field_code']['element_label_colon'] = FALSE;
  /* Kontextový filtr: Obsah: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Vše';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school_subject' => 'school_subject',
  );
  $translatables['reference_legal_subject_to_school_subject'] = array(
    t('Master'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Položek na stránku'),
    t('- Vše -'),
    t('Vynechat položky'),
    t('« první'),
    t('‹ předchozí'),
    t('následující ›'),
    t('poslední »'),
    t('No Results'),
    t('K tomuto předmětu se nevztahují žádné obory práva.'),
    t('Legal Subject'),
    t('Nadpis'),
    t('Kód'),
    t('Vše'),
  );
  $export['reference_legal_subject_to_school_subject'] = $view;

  $view = new view();
  $view->name = 'reference_school_subject_to_legal_subject';
  $view->description = 'Table displaying school subjects related to one legal subject';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'Reference: School Subject to Legal Subject';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Položek na stránku';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Vše -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Vynechat položky';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« první';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ předchozí';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'následující ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'poslední »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_code' => 'field_code',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Chování při žádných výsledcích: Globální: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'No results';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'K tomuto oboru práva se nevztahují žádné předměty.';
  /* Vztah: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_subjects_target_id']['id'] = 'field_school_subjects_target_id';
  $handler->display->display_options['relationships']['field_school_subjects_target_id']['table'] = 'field_data_field_school_subjects';
  $handler->display->display_options['relationships']['field_school_subjects_target_id']['field'] = 'field_school_subjects_target_id';
  $handler->display->display_options['relationships']['field_school_subjects_target_id']['label'] = 'School Subject';
  $handler->display->display_options['relationships']['field_school_subjects_target_id']['required'] = TRUE;
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_school_subjects_target_id';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Pole: Obsah: Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'field_data_field_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['relationship'] = 'field_school_subjects_target_id';
  $handler->display->display_options['fields']['field_code']['label'] = 'Kód';
  $handler->display->display_options['fields']['field_code']['element_label_colon'] = FALSE;
  /* Kontextový filtr: Obsah: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Vše';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'legal_subject' => 'legal_subject',
  );
  $translatables['reference_school_subject_to_legal_subject'] = array(
    t('Master'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Položek na stránku'),
    t('- Vše -'),
    t('Vynechat položky'),
    t('« první'),
    t('‹ předchozí'),
    t('následující ›'),
    t('poslední »'),
    t('No results'),
    t('K tomuto oboru práva se nevztahují žádné předměty.'),
    t('School Subject'),
    t('Nadpis'),
    t('Kód'),
    t('Vše'),
  );
  $export['reference_school_subject_to_legal_subject'] = $view;

  $view = new view();
  $view->name = 'school_subjects';
  $view->description = '';
  $view->tag = 'ESF';
  $view->base_table = 'node';
  $view->human_name = 'School Subjects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Obsah: Nadpis */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school_subject' => 'school_subject',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '|';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Pole: Obsah: Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'field_data_field_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['label'] = '';
  $handler->display->display_options['fields']['field_code']['element_label_colon'] = FALSE;

  /* Display: Table */
  $handler = $view->new_display('block', 'Table', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Pole: Obsah: Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'field_data_field_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['label'] = 'Kód';
  $handler->display->display_options['fields']['field_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextový filtr: Obsah: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Vše';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $translatables['school_subjects'] = array(
    t('Master'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Entity Reference'),
    t('Table'),
    t('Kód'),
    t('Vše'),
  );
  $export['school_subjects'] = $view;

  $view = new view();
  $view->name = 'stories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stories';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'více';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Použít';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Řadit dle';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Vzestupně';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Sestupně';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Položek na stránku';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Vše -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Vynechat položky';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« první';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ předchozí';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'následující ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'poslední »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Pole: Obsah: Nadpis */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Obsah: Datum vytvoření */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Obsah: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Obsah: Vydáno */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'stories';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Stories';
  $translatables['stories'] = array(
    t('Master'),
    t('Stories'),
    t('více'),
    t('Použít'),
    t('Reset'),
    t('Řadit dle'),
    t('Vzestupně'),
    t('Sestupně'),
    t('Položek na stránku'),
    t('- Vše -'),
    t('Vynechat položky'),
    t('« první'),
    t('‹ předchozí'),
    t('následující ›'),
    t('poslední »'),
    t('Page'),
    t('Block'),
  );
  $export['stories'] = $view;

  return $export;
}
