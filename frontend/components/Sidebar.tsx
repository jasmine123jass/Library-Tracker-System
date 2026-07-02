"use client";

import {
  LayoutDashboard,
  BookOpen,
  BarChart3,
  Users,
  Settings,
  LogOut,
} from "lucide-react";

const menuItems = [
  {
    title: "Dashboard",
    icon: LayoutDashboard,
  },
  {
    title: "Books",
    icon: BookOpen,
  },
  {
    title: "Analytics",
    icon: BarChart3,
  },
  {
    title: "Members",
    icon: Users,
  },
  {
    title: "Settings",
    icon: Settings,
  },
];

export default function Sidebar() {
  return (
    <aside className="w-72 min-h-screen bg-slate-900 border-r border-slate-800 flex flex-col">

      {/* Logo */}

      <div className="p-8 border-b border-slate-800">

        <h1 className="text-3xl font-bold text-blue-500">

          📚 Library

        </h1>

        <p className="text-slate-400 mt-2">

          Management System

        </p>

      </div>

      {/* Navigation */}

      <nav className="flex-1 p-6">

        <ul className="space-y-3">

          {menuItems.map((item) => {

            const Icon = item.icon;

            return (

              <li key={item.title}>

                <button
                  className="w-full flex items-center gap-4 px-4 py-3 rounded-xl text-slate-300 hover:bg-blue-600 hover:text-white transition-all duration-300"
                >

                  <Icon size={22} />

                  <span className="font-medium">

                    {item.title}

                  </span>

                </button>

              </li>

            );

          })}

        </ul>

      </nav>

      {/* Footer */}

      <div className="p-6 border-t border-slate-800">

        <button
          className="w-full flex items-center gap-4 px-4 py-3 rounded-xl bg-red-500 hover:bg-red-600 transition"
        >

          <LogOut size={20} />

          Logout

        </button>

      </div>

    </aside>
  );
}