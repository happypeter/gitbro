class Post < ActiveRecord::Base
  def grit
  require 'gollum'

  # Create a new Gollum::Wiki object by initializing it with the path to the
  # # Git repository.
  wiki = Gollum::Wiki.new("/home/peter/ll/")
  page = wiki.page('h')

  page.formatted_data
  end
end
