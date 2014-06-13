<?php

/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $id
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EntityValueWrapper $language
 */
class EbtWrapperItemLaw extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperItemLaw
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('item', $data, $info);
  }

  /**
   * @return EbtWrapperItemLaw
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_body
 * @property EntityValueWrapper $field_in_header
 * @property EntityValueWrapper $id
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EntityValueWrapper $language
 */
class EbtWrapperItemJoke extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperItemJoke
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('item', $data, $info);
  }

  /**
   * @return EbtWrapperItemJoke
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $id
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $field_body
 * @property EntityValueWrapper $field_in_header
 */
class EbtWrapperItem extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperItem
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('item', $data, $info);
  }

  /**
   * @return EbtWrapperItem
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_title_before
 * @property EntityValueWrapper $field_title_after
 * @property EntityValueWrapper $id
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EntityValueWrapper $full_name
 */
class EbtWrapperPersonLecturer extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperPersonLecturer
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('person', $data, $info);
  }

  /**
   * @return EbtWrapperPersonLecturer
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_title_before
 * @property EntityValueWrapper $field_title_after
 * @property EntityValueWrapper $id
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EntityValueWrapper $full_name
 */
class EbtWrapperPerson extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperPerson
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('person', $data, $info);
  }

  /**
   * @return EbtWrapperPerson
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 */
class EbtWrapperI18nTranslation extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperI18nTranslation
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('i18n_translation', $data, $info);
  }

  /**
   * @return EbtWrapperI18nTranslation
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodeNews extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodeNews
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodeNews
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $field_code
 * @property EntityListWrapper $field_school_subjects
 * @property EntityListWrapper $field_laws
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodeLegalSubject extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodeLegalSubject
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodeLegalSubject
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $field_code
 * @property EbtWrapperTaxonomyTerm $field_generality
 * @property EntityListWrapper $field_year
 * @property EntityListWrapper $field_materials
 * @property EntityListWrapper $field_study_texts
 * @property EntityListWrapper $field_lecturers
 * @property EntityStructureWrapper $field_postscript
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodeSchoolSubject extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodeSchoolSubject
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodeSchoolSubject
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodeStory extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodeStory
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodeStory
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodePage extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodePage
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodePage
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityListWrapper $field_materials
 * @property EntityValueWrapper $field_goal
 * @property EntityValueWrapper $field_id
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodeStudyText extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodeStudyText
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodeStudyText
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 */
class EbtWrapperNodeJoke extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNodeJoke
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNodeJoke
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityStructureWrapper $body
 * @property EntityValueWrapper $nid
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $is_new
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $title
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $promote
 * @property EntityValueWrapper $sticky
 * @property EntityValueWrapper $created
 * @property EntityValueWrapper $changed
 * @property EbtWrapperUser $author
 * @property EbtWrapperNode $source
 * @property EntityValueWrapper $log
 * @property EntityValueWrapper $revision
 * @property EntityValueWrapper $views
 * @property EntityValueWrapper $day_views
 * @property EntityValueWrapper $last_view
 * @property EntityValueWrapper $uuid
 * @property EntityValueWrapper $vuuid
 * @property EntityValueWrapper $field_code
 * @property EntityListWrapper $field_school_subjects
 * @property EntityListWrapper $field_laws
 * @property EbtWrapperTaxonomyTerm $field_generality
 * @property EntityListWrapper $field_year
 * @property EntityListWrapper $field_materials
 * @property EntityListWrapper $field_study_texts
 * @property EntityListWrapper $field_lecturers
 * @property EntityStructureWrapper $field_postscript
 * @property EntityValueWrapper $field_goal
 * @property EntityValueWrapper $field_id
 */
class EbtWrapperNode extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperNode
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('node', $data, $info);
  }

  /**
   * @return EbtWrapperNode
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_file_image_alt_text
 * @property EntityValueWrapper $field_file_image_title_text
 * @property EntityValueWrapper $fid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mime
 * @property EntityValueWrapper $size
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $timestamp
 * @property EbtWrapperUser $owner
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperFileImage extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperFileImage
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('file', $data, $info);
  }

  /**
   * @return EbtWrapperFileImage
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $fid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mime
 * @property EntityValueWrapper $size
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $timestamp
 * @property EbtWrapperUser $owner
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperFileVideo extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperFileVideo
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('file', $data, $info);
  }

  /**
   * @return EbtWrapperFileVideo
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $fid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mime
 * @property EntityValueWrapper $size
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $timestamp
 * @property EbtWrapperUser $owner
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperFileAudio extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperFileAudio
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('file', $data, $info);
  }

  /**
   * @return EbtWrapperFileAudio
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $fid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mime
 * @property EntityValueWrapper $size
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $timestamp
 * @property EbtWrapperUser $owner
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperFileDocument extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperFileDocument
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('file', $data, $info);
  }

  /**
   * @return EbtWrapperFileDocument
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_file_image_alt_text
 * @property EntityValueWrapper $field_file_image_title_text
 * @property EntityValueWrapper $fid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mime
 * @property EntityValueWrapper $size
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $timestamp
 * @property EbtWrapperUser $owner
 * @property EntityValueWrapper $type
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperFile extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperFile
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('file', $data, $info);
  }

  /**
   * @return EbtWrapperFile
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTermVocabulary9 extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTermVocabulary9
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTermVocabulary9
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTermVocabulary11 extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTermVocabulary11
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTermVocabulary11
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTermVocabulary12 extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTermVocabulary12
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTermVocabulary12
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTermLevelOfGenerality extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTermLevelOfGenerality
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTermLevelOfGenerality
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTermSchoolYear extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTermSchoolYear
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTermSchoolYear
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTermLawType extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTermLawType
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTermLawType
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $tid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $weight
 * @property EntityValueWrapper $node_count
 * @property EntityValueWrapper $url
 * @property EbtWrapperTaxonomyVocabulary $vocabulary
 * @property EntityListWrapper $parent
 * @property EntityListWrapper $parents_all
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperTaxonomyTerm extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyTerm
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_term', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyTerm
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $machine_name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $term_count
 */
class EbtWrapperTaxonomyVocabularyTaxonomyVocabulary extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyVocabularyTaxonomyVocabulary
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_vocabulary', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyVocabularyTaxonomyVocabulary
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $vid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $machine_name
 * @property EntityValueWrapper $description
 * @property EntityValueWrapper $term_count
 */
class EbtWrapperTaxonomyVocabulary extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperTaxonomyVocabulary
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('taxonomy_vocabulary', $data, $info);
  }

  /**
   * @return EbtWrapperTaxonomyVocabulary
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_aspi_username
 * @property EntityValueWrapper $uid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mail
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $last_access
 * @property EntityValueWrapper $last_login
 * @property EntityValueWrapper $created
 * @property EntityListWrapper $roles
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $theme
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperUserUser extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperUserUser
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('user', $data, $info);
  }

  /**
   * @return EbtWrapperUserUser
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


/**
 * show off @property, @property-read, @property-write
 *
 * @property EntityValueWrapper $field_aspi_username
 * @property EntityValueWrapper $uid
 * @property EntityValueWrapper $name
 * @property EntityValueWrapper $mail
 * @property EntityValueWrapper $url
 * @property EntityValueWrapper $edit_url
 * @property EntityValueWrapper $last_access
 * @property EntityValueWrapper $last_login
 * @property EntityValueWrapper $created
 * @property EntityListWrapper $roles
 * @property EntityValueWrapper $status
 * @property EntityValueWrapper $theme
 * @property EntityValueWrapper $language
 * @property EntityValueWrapper $uuid
 */
class EbtWrapperUser extends EntityDrupalWrapper
{
  /**
   * @return EbtWrapperUser
   */
  static function factory($data = NULL, array $info = array())
  {
    return entity_metadata_wrapper('user', $data, $info);
  }

  /**
   * @return EbtWrapperUser
   */
  static function cast($wrapper)
  {
    return $wrapper;
  }
}


