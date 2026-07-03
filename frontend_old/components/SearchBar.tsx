"use client";

import { Search } from "lucide-react";

interface Props {
  search: string;
  setSearch: (value: string) => void;
}

export default function SearchBar({
  search,
  setSearch,
}: Props) {

  return (

    <div className="relative w-80">

      <Search
        size={20}
        className="absolute left-4 top-3.5 text-slate-400"
      />

      <input
        type="text"
        placeholder="Search books..."
        value={search}
        onChange={(e) => setSearch(e.target.value)}
        className="w-full bg-slate-900 border border-slate-700 rounded-xl py-3 pl-12 pr-4 outline-none focus:border-blue-500 transition"
      />

    </div>

  );

}