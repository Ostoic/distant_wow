#pragma once

#include "unit.hpp"
#include "types.hpp"
#include "detail/player_descriptors.hpp"

namespace wow::objects
{
	class player : public unit
	{
	public:
		enum class classes;

	public: // interface
		std::size_t display_id() const override final;

		bool is_player() const override;

		void change_name(const std::string& name) override final;

	public: // {ctor}
		player() = default;
		explicit player(memory::address base);

	protected:
		void update_data() const override final;

	private: // implementation functions
		friend class object;

	private: // data
		mutable memory::address descriptors_base_;
		//mutable std::shared_ptr<detail::player_descriptors> player_descriptors_;
	};
} // namespace wow::objects

namespace wow
{
	using objects::player;
}