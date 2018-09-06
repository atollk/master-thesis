
#include "../construction_main.h"
#include "path_refinement.h"

using namespace tollk;

class IMConstructionExecutor : public ConstructionExecutor {
 public:
    std::string ConstructionName() const override {
        return "path refinement";
    }
};

std::unique_ptr<ConstructionExecutor> CreateConstructionExecutor() {
    return std::make_unique<IMConstructionExecutor>();
}


tollk::automaton::DPA PerformConstruction(tollk::automaton::DPA dpa, const BaseOptions& options) {
    //TODO use better relation
    EquivalenceRelation<automaton::state_t> R = dpa.LabelEquivalence();
    automaton::RefineToCongruence(&R, dpa);

    const EquivalenceRelation<automaton::state_t> pr = PathRefinementEquivalence(dpa, R);
    QuotientAutomatonUnsafe(&dpa, pr);
    return dpa;
}
