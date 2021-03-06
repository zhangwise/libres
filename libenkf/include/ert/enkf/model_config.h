/*
   Copyright (C) 2011  Statoil ASA, Norway.

   The file 'model_config.h' is part of ERT - Ensemble based Reservoir Tool.

   ERT is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ERT is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.

   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html>
   for more details.
*/

#ifndef ERT_MODEL_CONFIG_H
#define ERT_MODEL_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <time.h>

#include <ert/util/path_fmt.h>
#include <ert/util/type_macros.h>

#include <ert/config/config_parser.h>
#include <ert/config/config_content.h>

#include <ert/job_queue/ext_joblist.h>
#include <ert/job_queue/forward_model.h>

#include <ert/sched/history.h>
#include <ert/sched/sched_file.h>

#include <ert/ecl/ecl_sum.h>

#include <ert/enkf/enkf_types.h>
#include <ert/enkf/fs_types.h>
#include <ert/enkf/time_map.h>

  typedef struct model_config_struct model_config_type;
  const char *           model_config_get_data_root( const model_config_type * model_config );
  void                   model_config_set_data_root( model_config_type * model_config , const char * data_root);
  bool                   model_config_data_root_is_set( const model_config_type * model_config );

  char                 * model_config_alloc_jobname( const model_config_type * model_config , int iens);
  const char *           model_config_get_jobname_fmt( const model_config_type * model_config );
  void                   model_config_set_jobname_fmt( model_config_type * model_config , const char * jobname_fmt);
  void                   model_config_set_enspath( model_config_type * model_config , const char * enspath);
  void                   model_config_set_rftpath( model_config_type * model_config , const char * rftpath);
  void                   model_config_set_dbase_type( model_config_type * model_config , const char * dbase_type_string);
  void                 * model_config_get_dbase_args( const model_config_type * model_config );
  const char           * model_config_get_enspath( const model_config_type * model_config);
  const char           * model_config_get_rftpath( const model_config_type * model_config);
  fs_driver_impl         model_config_get_dbase_type(const model_config_type * model_config );
  const ecl_sum_type   * model_config_get_refcase( const model_config_type * model_config );
  void                   model_config_init_internalization( model_config_type * );
  void                   model_config_set_internalize_state( model_config_type *  , int );
  void                   model_config_set_load_state( model_config_type *  , int );
  int                    model_config_get_history_length(const model_config_type * );
  bool                   model_config_has_prediction(const model_config_type * );
  bool                   model_config_has_history(const model_config_type * config);
  int                    model_config_get_last_history_restart(const model_config_type * );
  time_map_type        * model_config_get_external_time_map( const model_config_type * config);
  int                    model_config_get_num_realizations(const model_config_type * model_config);
  const char           * model_config_get_obs_config_file(const model_config_type * model_config);
  void                   model_config_init(model_config_type * model_config , const config_content_type * , const char * data_root, int ens_size , const ext_joblist_type * , int , const sched_file_type * , const ecl_sum_type * refcase);
  void                   model_config_free(model_config_type *);
  bool                   model_config_runpath_requires_iter( const model_config_type * model_config );
  path_fmt_type        * model_config_get_runpath_fmt(const model_config_type * );
  history_type         * model_config_get_history(const model_config_type * );
  forward_model_type   * model_config_get_forward_model( const model_config_type * );
  bool                   model_config_internalize_state( const model_config_type *, int );
  bool                   model_config_load_state( const model_config_type *, int );
  const char           * model_config_iget_casename( const model_config_type * model_config , int index);
  //void                   model_config_set_max_resample( model_config_type * model_config , int max_resample );
  //int                    model_config_get_max_resample(const model_config_type * model_config );
  void                   model_config_set_max_internal_submit(model_config_type * config, int max_resample);
  int                    model_config_get_max_internal_submit( const model_config_type * config );
  bool                   model_config_select_runpath( model_config_type * model_config , const char * path_key);
  void                   model_config_add_runpath( model_config_type * model_config , const char * path_key , const char * fmt );
  const char           * model_config_get_runpath_as_char( const model_config_type * model_config );
  history_source_type    model_config_get_history_source( const model_config_type * model_config );
  void                   model_config_set_refcase( model_config_type * model_config , const ecl_sum_type * refcase );
  void                   model_config_fprintf_config( const model_config_type * model_config , int ens_size ,FILE * stream );
  model_config_type    * model_config_alloc_empty();
  model_config_type    * model_config_alloc_load(const char*, const ext_joblist_type*, int, const sched_file_type*, const ecl_sum_type*);
  model_config_type    * model_config_alloc(const config_content_type*, const char * data_root, const ext_joblist_type *, int, const sched_file_type *, const ecl_sum_type*);

  bool                   model_config_select_history( model_config_type * model_config , history_source_type source_type, const sched_file_type * schede_file , const ecl_sum_type * refcase);
  void                   model_config_set_runpath(model_config_type * model_config , const char * fmt);
  void                   model_config_set_gen_kw_export_name( model_config_type * model_config, const char * name);
  const char           * model_config_get_gen_kw_export_name( const model_config_type * model_config);

  config_content_type  * model_config_alloc_content(const char*, config_parser_type*);
  void                   model_config_init_config_parser(config_parser_type * config_parser);
  bool                   model_config_report_step_compatible(const model_config_type * model_config, const ecl_sum_type * ecl_sum_simulated);
  
  UTIL_IS_INSTANCE_HEADER( model_config);

#ifdef __cplusplus
}
#endif
#endif


