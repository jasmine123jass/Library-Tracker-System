"use client";

import {
  Bell,
  Search,
  Moon,
  UserCircle2,
} from "lucide-react";

export default function Navbar() {
  return (
    <header className="h-20 border-b border-slate-800 bg-slate-900 flex items-center justify-between px-8">

      {/* Search */}

      <div className="relative w-[420px]">

        <Search
          size={18}
          className="absolute left-4 top-1/2 -translate-y-1/2 text-slate-400"
        />

        <input
          type="text"
          placeholder="Search books..."
          className="w-full rounded-xl bg-slate-800 border border-slate-700 pl-12 pr-4 py-3 outline-none focus:border-blue-500"
        />

      </div>

      {/* Right Side */}

      <div className="flex items-center gap-5">

        <button className="w-11 h-11 rounded-xl bg-slate-800 hover:bg-blue-600 transition flex items-center justify-center">

          <Moon size={20} />

        </button>

        <button className="w-11 h-11 rounded-xl bg-slate-800 hover:bg-blue-600 transition flex items-center justify-center">

          <Bell size={20} />

        </button>

        <div className="flex items-center gap-3 bg-slate-800 rounded-xl px-4 py-2">

          <UserCircle2
            size={36}
            className="text-blue-400"
          />

          <div>

            <h3 className="font-semibold">

              Srujitha

            </h3>

            <p className="text-xs text-slate-400">

              Administrator

            </p>

          </div>

        </div>

      </div>

    </header>
  );
}