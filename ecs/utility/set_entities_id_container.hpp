#ifndef ECS_INCLUDE_UTILITY_SET_ENTITIES_ID_CONTAINER_HPP_
#define ECS_INCLUDE_UTILITY_SET_ENTITIES_ID_CONTAINER_HPP_

#include <ecs/entity/entities_id_container.hpp>
#include <set>

namespace ecs {
namespace util {

class SetEntitiesIdContainer : public entity::EntitiesIdContainer {
 public:
  void Insert(const EntityId& entity_id) override;
  void Remove(const EntityId& entity_id) override;

 private:
  std::set<EntityId> entities_set_;
};

}  // namespace util
}  // namespace ecs

#endif  // ECS_INCLUDE_UTILITY_SET_ENTITIES_ID_CONTAINER_HPP_
