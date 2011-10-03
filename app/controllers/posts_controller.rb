class PostsController < ApplicationController
  # GET /posts
  # GET /posts.xml
  def index
    require 'gollum'
    @wiki = Gollum::Wiki.new("/home/peter/ll/")
    require 'grit'
    @repo = Grit::Repo.new("/home/peter/ll")
    @tree = @repo.commits.first.tree
    respond_to do |format|
      format.html # index.html.erb
      format.xml  { render :xml => @posts }
    end
  end

  # GET /posts/1
  # GET /posts/1.xml
  def show
    @wiki = Gollum::Wiki.new("/home/peter/ll/")
    @page =  @wiki.page(params[:page_name])

    respond_to do |format|
      format.html # show.html.erb
      format.xml  { render :xml => @post }
    end
  end

  # GET /posts/new
  # GET /posts/new.xml
  def new
    respond_to do |format|
      format.html # new.html.erb
      format.xml  { render :xml => @post }
    end
  end

  # GET /posts/1/edit
  def edit
    @wiki = Gollum::Wiki.new("/home/peter/ll/")
    @page =  @wiki.page(params[:page_name])
  end

  # POST /posts
  # POST /posts.xml
  def create
    
    @commit = { :message => 'commit message',
               :name => 'Tom Preston-Werner',
               :email => 'tom@github.com' }
    @wiki = Gollum::Wiki.new("/home/peter/ll/")
    @page = @wiki.page(params[:post][:title])
    @wiki.write_page(params[:post][:title], :markdown, params[:post][:content], @commit)

    respond_to do |format|
        format.html { redirect_to(root_url, :notice => 'successfully updated.') }
        format.xml  { head :ok }
    end
  end

  # PUT /posts/1
  # PUT /posts/1.xml
  def update
    @commit = { :message => 'commit message',
               :name => 'Tom Preston-Werner',
               :email => 'tom@github.com' }
               
    @wiki = Gollum::Wiki.new("/home/peter/ll/")
    @page = @wiki.page(params[:page_name])
    @wiki.update_page(@page,@page.name, @page.format, params[:post][:content], @commit)
    respond_to do |format|
        format.html { redirect_to(root_url, :notice => 'successfully updated.') }
        format.xml  { head :ok }
    end
  end

  # DELETE /posts/1
  # DELETE /posts/1.xml
  def destroy
    @post = Post.find(params[:id])
    @post.destroy

    respond_to do |format|
      format.html { redirect_to(posts_url) }
      format.xml  { head :ok }
    end
  end
end
