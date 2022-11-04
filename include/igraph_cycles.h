
#ifndef IGRAPH_CYCLES_H
#define IGRAPH_CYCLES_H

#include "igraph_datatype.h"
#include "igraph_decls.h"
#include "igraph_error.h"
#include "igraph_types.h"
#include "igraph_vector_list.h"

__BEGIN_DECLS

IGRAPH_EXPORT igraph_error_t igraph_fundamental_cycles(
    const igraph_t *graph, igraph_vector_int_list_t *result,
    igraph_integer_t start_vid, igraph_integer_t bfs_cutoff,
    const igraph_vector_t *weights);

IGRAPH_EXPORT igraph_error_t igraph_minimum_cycle_basis(
    const igraph_t *graph, igraph_vector_int_list_t *result,
    igraph_integer_t bfs_cutoff, igraph_bool_t complete,
    igraph_bool_t use_cycle_order, const igraph_vector_t *weights);

struct igraph_simple_cycle_search_state_t;

IGRAPH_EXPORT igraph_error_t igraph_simple_cycle_search_state_init(
    struct igraph_simple_cycle_search_state_t *state, const igraph_t *graph);

IGRAPH_EXPORT igraph_error_t igraph_simple_cycle_search_state_destroy(
    struct igraph_simple_cycle_search_state_t *state);

IGRAPH_EXPORT igraph_error_t igraph_simple_cycles_search_from_one_vertex(
    struct igraph_simple_cycle_search_state_t *state, igraph_integer_t start,
    igraph_vector_int_list_t *result,
    igraph_simple_cycle_search_mode_t search_mode);

IGRAPH_EXPORT igraph_error_t igraph_simple_cycles_search_all(
    const igraph_t *graph, igraph_vector_int_list_t *result,
    igraph_simple_cycle_search_mode_t search_mode);

__END_DECLS

#endif
