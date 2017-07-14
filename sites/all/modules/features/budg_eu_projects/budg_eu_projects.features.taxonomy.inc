<?php
/**
 * @file
 * budg_eu_projects.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function budg_eu_projects_taxonomy_default_vocabularies() {
  return array(
    'budget_broad_areas' => (object) array(
      'name' => 'Budget broad areas',
      'machine_name' => 'budget_broad_areas',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'budget_eu_projects',
      'weight' => -7,
      'language' => 'und',
      'i18n_mode' => 1,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'campaign' => (object) array(
      'name' => 'Campaign',
      'machine_name' => 'campaign',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'dgt_editors' => (object) array(
      'name' => 'DGT Editors',
      'machine_name' => 'dgt_editors',
      'description' => 'The name of the editor',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'eu_budget_mff_headings' => (object) array(
      'name' => 'EU Budget MFF headings',
      'machine_name' => 'eu_budget_mff_headings',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'budget_eu_projects',
      'weight' => -10,
      'language' => 'und',
      'i18n_mode' => 1,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'eu_priorities' => (object) array(
      'name' => 'The EC’s 10 priorities',
      'machine_name' => 'eu_priorities',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'budget_eu_projects',
      'weight' => -8,
      'language' => 'und',
      'i18n_mode' => 1,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'mff_programmes' => (object) array(
      'name' => 'MFF Programmes',
      'machine_name' => 'mff_programmes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'budget_eu_projects',
      'weight' => -9,
      'language' => 'und',
      'i18n_mode' => 1,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
